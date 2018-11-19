#include "Shader.h"
#include "Texture.h"
#include <fstream>
#include <iostream>

#include <glm/ext.hpp>


GLuint Shader::getID()
{
	return id;
}

void Shader::load(std::string path)
{
	this->path = path;
}
void Shader::create(std::string vert, std::string frag)
{
	//firstly read in vertex shader
	std::ifstream file(vert.c_str());
	std::string vertS;
	if (!file)
	{
		throw std::exception();
	}
	while(!file.eof())
		{
		std::string line;
		std::getline(file, line);
		vertS += line + "\n";
		}

	//now open and read fragment shader
	file.close();
	file.open(frag.c_str());
	std::string fragS;

	if (!file)
	{
		throw std::exception();
	}
	while(!file.eof())
		{
		std::string line;
		std::getline(file, line);
		fragS += line + "\n";
		}

	file.close();

	//set up shaders for GL
	const GLchar *VertShad =vertS.c_str();
	GLuint vertShadID =glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShadID,1,&VertShad,NULL);
	glCompileShader(vertShadID);
	GLint success=0;
	glGetShaderiv(vertShadID, GL_COMPILE_STATUS, &success);

	if (!success)
	{//error
		std::exception();
	}	
	
	const GLchar *FragShad =fragS.c_str();
	GLuint fragShadID =glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShadID,1,&FragShad,NULL);
	glCompileShader(fragShadID);
	glGetShaderiv(fragShadID, GL_COMPILE_STATUS, &success);

	if (!success)
	{//error
		std::exception();
	}

	//create Program

	id=glCreateProgram();
	glAttachShader(id, vertShadID);
	glAttachShader(id, fragShadID);
	glBindAttribLocation(id, 0, "in_Position");
  	glBindAttribLocation(id, 1, "in_Color");
  	glBindAttribLocation(id, 2, "in_TexCoord");
 	 glBindAttribLocation(id, 3, "in_Normal");


	glLinkProgram(id);
	glGetProgramiv(id,GL_LINK_STATUS, &success);

	if (!success)
	{	
		throw std::exception();
	}

	glDetachShader(id, vertShadID);
	glDeleteShader(vertShadID);
	glDetachShader(id, fragShadID);
	glDeleteShader(fragShadID);
}


void Shader::setUniform (std::string name, glm::vec4 value)
{
	GLint uniformID = glGetUniformLocation(id, name.c_str());
	if(uniformID == -1)
 		 {
  		  throw std::exception();
  		}

	glUseProgram(id);
	glUniform4f(uniformID, value.x,value.y,value.z, value.w);
	glUseProgram(0);

}
void Shader::setUniform(std::string name, float value)
{
	GLint uniformId = glGetUniformLocation(id, name.c_str());

 	 if(uniformId == -1)
 	 {
  	  throw std::exception();
 	 }

 	 glUseProgram(id);
 	 glUniform1i(uniformId, value);
  	 glUseProgram(0);


}

void Shader::setUniform(std::string name, glm::vec3 value)
{
	GLint uniformID = glGetUniformLocation(id, name.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}
	
	glUseProgram(id);
	glUniform3f(uniformID, value.x, value.y, value.z);
	glUseProgram(0);
}

void Shader::setUniform(std::string name, glm::mat4 value) 
{
	GLint uniformID = glGetUniformLocation(id, name.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(value));
	glUseProgram(0);



}

void Shader::setUniform (std::string name, std::weak_ptr<Texture> value)
{
	GLint uniformID = glGetUniformLocation(id, name.c_str());
	if(uniformID == -1)
 		 {
  		  throw std::exception();
  		}

	glUseProgram(id);
	glUniform1i(uniformID, 0);
	glUseProgram(0);
	return;


	
	//step through resources till *Texture.id = uniformid
		/*
		glUseProgram(id);
		glUniform1i(uniformID, *forloopcounter*);
   		glUseProgram(0);
     		 return;
			 */
		
	//if no texture matches (which it should but still) create default and put into resources, use that as uniform
}