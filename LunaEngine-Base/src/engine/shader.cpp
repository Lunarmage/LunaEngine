#include "Shader.h"

#include <fstream>
#include <iostream>

void Shader::create(std::string vert, std::string frag)
{
	//firstly read in vertex shader
	std::ifstream file(vert.c_str());
	std::string vertS;

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
	while(!file.eof())
		{
		std::string line;
		std::getline(file, line);
		fragS += line + "\n";
		}
	//set up shaders for GL
	const GLchar *VertShad =vertS.c_str();
	GLuint vertShadID =glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShadID,1,&VertShad,NULL);
	glCompileShader(vertShadID);
	GLint success=0;
	glGetShaderiv(vertShadID, GL_COMPILE_STATUS, &success);
	if (!success)
	{//error
	}	
	
	const GLchar *FragShad =fragS.c_str();
	GLuint fragShadID =glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShadID,1,&FragShad,NULL);
	glCompileShader(fragShadID);
	glGetShaderiv(fragShadID, GL_COMPILE_STATUS, &success);
	if (!success)
	{//error
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
	{//error
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
 	 glUniform1f(uniformId, value);
  	 glUseProgram(0);


}

void Shader::setUniform (std::string name, std::weak_ptr<Texture> value)
{
	GLint uniformID = glGetUniformLocation(id, name.c_str());
	if(uniformID == -1)
 		 {
  		  throw std::exception();
  		}
	//step through resources till *Texture.id = uniformid
		/*
		glUseProgram(id);
		glUniform1i(uniformId, *forloopcounter*);
   		glUseProgram(0);
     		 return;

		*/
	//if no texture matches (which it should but still) create default and put into resources, use that as uniform
}