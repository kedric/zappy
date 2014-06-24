#!/usr/bin/env python
from classes import *

class MyClient:
    srv = None

    def __init__(self, kwargs):
        try:
            self.srv = MyServer(kwargs)
            self.srv.bind()
        except Exception as e:
            print e
            sys.exit(0)
    def play(self):
        try:
            self.srv.init_trant()
            self.srv.loop()
        except KeyboardInterrupt: pass
        self.srv.leave()
        del self.srv

client = MyClient(sys.argv)
client.play()
del client
