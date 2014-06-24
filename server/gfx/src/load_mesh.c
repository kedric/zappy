/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noumazza <noumazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 05:49:56 by noumazza          #+#    #+#             */
/*   Updated: 2014/06/09 18:49:52 by noumazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static void	fill_buffers(int point_count, GLfloat **buffers, \
		const struct aiMesh *mesh)
{
	int	i;
	const struct aiVector3D	*vp;

	i = -1;
	while (++i < point_count)
	{
		vp = &(mesh->mVertices[i]);
		buffers[0][i * 3] = (GLfloat)vp->x;
		buffers[0][i * 3 + 1] = (GLfloat)vp->y;
		buffers[0][i * 3 + 2] = (GLfloat)vp->z;
		vp = &(mesh->mNormals[i]);
		buffers[1][i * 3] = (GLfloat)vp->x;
		buffers[1][i * 3 + 1] = (GLfloat)vp->y;
		buffers[1][i * 3 + 2] = (GLfloat)vp->z;
		if (buffers[2])
		{
			vp = &(mesh->mTextureCoords[0][i]);
			buffers[2][i * 2] = (GLfloat)vp->x;
			buffers[2][i * 2 + 1] = (GLfloat)vp->y;
		}
	}
}

static void	copy_into_vao(const struct aiMesh *mesh, int point_count)
{
	GLfloat	**buffs;
	GLuint	vbo;
	int		i;
	int		max;
	int		dimension;

	if (mesh->mVertices && mesh->mNormals)
	{
		buffs = (GLfloat **)malloc(sizeof(GLfloat *) * 3);
		buffs[0] = (GLfloat *)malloc(sizeof(GLfloat) * 3 * point_count);
		buffs[1] = (GLfloat *)malloc(sizeof(GLfloat) * 3 * point_count);
		buffs[2] = NULL;
		if (mesh->mTextureCoords[0])
			buffs[2] = (GLfloat *)malloc(sizeof(GLfloat) * 2 * point_count);
		fill_buffers(point_count, buffs, mesh);
		max = mesh->mTextureCoords[0] ? 3 : 2;
		i = -1;
		while (++i < max)
		{
			dimension = i == 2 ? 2 : 3;
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, \
				dimension * point_count * sizeof (GLfloat), \
				buffs[i], GL_STATIC_DRAW);
			glVertexAttribPointer(i, dimension, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(i);
			free(buffs[i]);
		}
	}
	free(buffs);
}

int			load_meshes(char *file, t_scene *scene, int index)
{
	const struct aiScene	*aiscene;
	const struct aiMesh	*mesh;

	aiscene = aiImportFile(file, aiProcess_Triangulate);
	if (!aiscene)
		return (ft_error((char *)aiGetErrorString()));
	printf ("  %i animations\n", aiscene->mNumAnimations);
	printf ("  %i cameras\n", aiscene->mNumCameras);
	printf ("  %i lights\n", aiscene->mNumLights);
	printf ("  %i materials\n", aiscene->mNumMaterials);
	printf ("  %i meshes\n", aiscene->mNumMeshes);
	printf ("  %i textures\n", aiscene->mNumTextures);
	glGenVertexArrays(1, &scene->objects[index].vao);
	glBindVertexArray(scene->objects[index].vao);
	mesh = aiscene->mMeshes[0];
	printf ("    %i vertices in mesh[%d]\n", mesh->mNumVertices, \
			scene->object_count);
	scene->objects[index].point_count = mesh->mNumVertices;
	copy_into_vao(mesh, mesh->mNumVertices);
	scene->object_count++;
	aiReleaseImport(aiscene);
}
