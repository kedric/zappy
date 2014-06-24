#!/usr/bin/env python
import sys
import os
import socket
import select
import getopt
import re
from parse import *

class MyCommand:

    # Vaut pour les commandes "broadcast", "fork", "avance", "droite" et "gauche"
    def simple_action(self, answer, player):
        player.last_action = None

    def inventaire(self, player, string):
        player.inventory['nourriture'], player.inventory['linemate'], \
                player.inventory['deraumere'], player.inventory['sibur'], \
                player.inventory['mendiane'], player.inventory['phiras'], \
                player.inventory['thystame'] = search('{nourriture {:d}, linemate {:d}, deraumere {:d}, sibur {:d}, mendiane {:d}, phiras {:d}, thystame {:d}}\n', string)
        player.last_action = None

    def voir(self, player, ans):
        player.view = [[''] for x in xrange(18)]
        player.last_action = None
        print ans
        if ans == "ko":
            return
        ans = re.sub("[{}]", '', ans)
        spl = ans.split(",")
        i = 0
        while i < len(spl):
            player.view[i] = spl[i].split(" ")
            i = i + 1
        print "PLAYER VIEW: "
        print player.view

    def incant(self, player, ans):
        if ans == "incantation en cours\n":
            return
        player.last_action = None
        if ans == "ko\n":
            return
        if 'niveau actuel' in ans:
            player.level = search('niveau actuel : {:d}\n', ans)

    def prend(self, player, ans, obj):
        if ans == ok:
            player.inventory[obj] += 1
        else:
            player.update = 1
        player.last_action = None

    def expulse(self, player, ans):
        if ans == ko:
            player.update_v = 1
        player.last_action = None

    def pose(self, player, ans, obj):
        if ans == ok:
            player.inventory[obj] -= 1
        else:
            player.update = 1
        player.last_action = None

    def connect_nbr(self, player, ans):
        player.nb = search('{:d}\n', ans)
        player.last_action = None

    def fork_client(self, team_name, port, host):
        player.last_action = None
        child = os.fork()
        if child == 0:
            os.execl(sys.argv[0], sys.argv[0], "-n", team_name, "-p", str(port), "-h", str(host))
            sys.exit(0)
        return

class MyPlayer:

    last_action = None
    level = 1
    view = [[''] for x in xrange(18)]
    update_i = 0
    update_v = 0
    inventory = None
    game_vision = None
    nb = None
    pos = None
    __team = None

    def __init__(self, team, nb, pos):
        self.inventory = {}
        self.__team = team
        self.pos = pos
        self.nb = nb
        self.inventory['nourriture'] = 0
        self.inventory['linemate'] = 0
        self.inventory['deraumere'] = 0
        self.inventory['sibur'] = 0
        self.inventory['mendiane'] = 0
        self.inventory['phiras'] = 0
        self.inventory['thystame'] = 0
        print 'New Trantorian, slots remaining :', self.nb, ' | team', self.__team,'| map size', self.pos[0],':', self.pos[1]

    def action(message):
        return

class MyServer:

    __usage = "Usage: ./client -n <team> -p <port> [-h <hostname>]\n-n nom d'equipe\n-p port\n-h nom de la machine par defaut c'est le localhost"
    __host = None
    __port = None
    __optlist = None
    __sock = None
    __adr = None
    trantorian = None

    def __init__(self, kwargs):
        self.__team = None
        self.__optlist, args= getopt.getopt(kwargs[1:], ':n:p:h:')
        if args:
            raise Exception(self.__usage)
        for o, a in self.__optlist:
            if o == "-n":
                self.__team = a
            elif o == "-h":
                self.__host = a
            elif o == "-p":
                self.__port = a
        if not self.__team or not self.__port:
            raise Exception(self.__usage)
        if not self.__host:
            self.__host = 'localhost'

    # Connecte le client au serveur, initialise le socket
    def bind(self):
        self.__sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.__adr = (self.__host, int(self.__port))
        try:
            self.__sock.connect(self.__adr)
        except Exception as e:
            raise Exception(e)
        print 'starting up on %s port %s' % self.__adr

    # Initialise l'objet trantorian avec les infos renvoyees par le serveur
    def init_trant(self):
        pos = -1
        number = -1
        while 42:
            if self.__receive() == 'BIENVENUE\n':
                break
        self.msg(self.__team)
        while number == -1 or number == None:
            try:
                number, x, y = search('{:d}\n{:d} {:d}\n', self.__receive())
            except Exception: pass
        self.trantorian = MyPlayer(self.__team, number, (x, y))

    #envoi le message passe en parametre au serveur, ajoute un \n
    def msg(self, msg):
        msg = str(msg)
        msg += "\n"
        self.__sock.sendall(msg)

    def __receive(self):
            return self.__sock.recv(1024)

    def getsock(self):
        return self.__sock

    def leave(self):
        self.__sock.close()
        print '\n==== Socket Closed ====\n'

    def loop(self):
        line = 0
        cmd = MyCommand()
        #if self.trantorian.nb > 0:
        #    cmd.fork_client(self.__team, self.__port, self.__host)
        while 42:
            readable, writable, dick = select.select([sys.stdin, self.__sock], [], [])
            for s in readable:
                if s is sys.stdin:
                    line = sys.stdin.readline()
                    if line == 'quit\n' or not line:
                        return
                    self.msg(line)
                    if line == 'inventaire\n':
                        cmd.inventaire(self.trantorian, self.__receive())
                        print "MY INVENTORY"
                        print self.trantorian.inventory
                    if line == 'voir\n':
                        cmd.voir(self.trantorian, self.__receive().split("\n", 1024)[0])
                if s is self.__sock:
                    print self.__receive().rstrip()
