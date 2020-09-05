// Example 1: Load and Print
//
// Load the data from the .obj then print it into a file
//	called e1Out.txt

// Iostream - STD I/O Library
#include <iostream>

// fStream - STD File I/O Library
#include <fstream>

// OBJ_Loader - .obj Loader
#include "OBJ_Loader.h"

// Main function
int main(int argc, char* argv[])
{
	// Initialize Loader
	objl::Loader Loader;

	// Load .obj File
	bool loadout = Loader.LoadFile("box_stack.obj");

	// Check to see if it loaded

	// If so continue
	if (loadout)
	{
		// Create/Open e1Out.txt
		std::ofstream file("e1Out.txt");

		// Go through each loaded mesh and out its contents
		for (int i = 0; i < Loader.LoadedMeshes.size(); i++)
		{
			// Copy one of the loaded meshes to be our current mesh
			objl::Mesh curMesh = Loader.LoadedMeshes[i];

			// Print Mesh Name
			file << "Mesh " << i << ": " << curMesh.MeshName << "\n";

			// Print Vertices
			file << "Vertices:\n";

			// Go through each vertex and print its number,
			//  position, normal, and texture coordinate
			for (int j = 0; j < curMesh.Vertices.size(); j++)
			{
				file << "V" << j << ": " <<
					"P(" << curMesh.Vertices[j].Position.x << ", " << curMesh.Vertices[j].Position.y << ", " << curMesh.Vertices[j].Position.z << ") " <<
					"N(" << curMesh.Vertices[j].Normal.x << ", " << curMesh.Vertices[j].Normal.y << ", " << curMesh.Vertices[j].Normal.z << ") " <<
					"TC(" << curMesh.Vertices[j].TextureCoordinate.x << ", " << curMesh.Vertices[j].TextureCoordinate.y << ") " << 
					"Tangent(" << curMesh.Vertices[j].tangent.x << ", " << curMesh.Vertices[j].tangent.y << ", " << curMesh.Vertices[j].tangent.z << ")\n";
			}

			// Print Indices
			file << "Indices:\n";

			// Go through every 3rd index and print the
			//	triangle that these indices represent
			for (int j = 0; j < curMesh.Indices.size(); j += 3)
			{
				file << "T" << j / 3 << ": " << curMesh.Indices[j] << ", " << curMesh.Indices[j + 1] << ", " << curMesh.Indices[j + 2] << "\n";
			}

			file << "Bounding Box:\n";
			file << "Min: " << curMesh.bboxMin.x << ", " << curMesh.bboxMin.y << ", " << curMesh.bboxMin.z << "\n";
			file << "Max: " << curMesh.bboxMax.x << ", " << curMesh.bboxMax.y << ", " << curMesh.bboxMax.z << "\n";

			// Print Material
			file << "Material: " << curMesh.MeshMaterial.name << "\n";
			file << "Ambient Color: " << curMesh.MeshMaterial.Ka.x << ", " << curMesh.MeshMaterial.Ka.y << ", " << curMesh.MeshMaterial.Ka.z << "\n";
			file << "Diffuse Color: " << curMesh.MeshMaterial.Kd.x << ", " << curMesh.MeshMaterial.Kd.y << ", " << curMesh.MeshMaterial.Kd.z << "\n";
			file << "Specular Color: " << curMesh.MeshMaterial.Ks.x << ", " << curMesh.MeshMaterial.Ks.y << ", " << curMesh.MeshMaterial.Ks.z << "\n";
			file << "Specular Exponent: " << curMesh.MeshMaterial.Ns << "\n";
			file << "Optical Density: " << curMesh.MeshMaterial.Ni << "\n";
			file << "Dissolve: " << curMesh.MeshMaterial.d << "\n";
			file << "Illumination: " << curMesh.MeshMaterial.illum << "\n";
			file << "Ambient Texture Map: " << curMesh.MeshMaterial.map_Ka << "\n";
			file << "Diffuse Texture Map: " << curMesh.MeshMaterial.map_Kd << "\n";
			file << "Specular Texture Map: " << curMesh.MeshMaterial.map_Ks << "\n";
			file << "Alpha Texture Map: " << curMesh.MeshMaterial.map_d << "\n";
			file << "Bump Map: " << curMesh.MeshMaterial.map_bump << "\n";

			// Leave a space to separate from the next mesh
			file << "\n";
		}

		// Close File
		file.close();
	}
	// If not output an error
	else
	{
		// Create/Open e1Out.txt
		std::ofstream file("e1Out.txt");

		// Output Error
		file << "Failed to Load File. May have failed to find it or it was not an .obj file.\n";

		// Close File
		file.close();
	}

	// Exit the program
	return 0;
}