/*Copyright 2008-2024 - Lo�c Le Cunff

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.*/

#include <logger.h>
 #include <lua_structure.h>

#include <fstream>
#include <iostream>
#include <sstream>

int ageom_converter(int argc,char *argv[])
{
	std::stringstream geostr, output;
	
	geostr<<"declare_parameter(\"str\",10)\n";
	output<<"declare_parameter(\"str\",10)\n";
	
	geostr<<"lx(\"lx_str\")\n";
	output<<"lx=lx_str\n";
	
	geostr<<"ly(\"ly_str\")\n";
	output<<"ly=ly_str\n";
	
	geostr<<"lz(\"lz_str\")\n";
	output<<"lz=lz_str\n";
	
	geostr<<"set(\"var\",\"var_str\")";
	output<<"var=var_str\n";
	
	geostr<<"default_material(0)\n";
	output<<"default_material(0)\n";
	
	geostr<<"add_block(\"arg1\",\"arg2\",\"arg3\",\"arg4\",\"arg5\",\"arg6\",1)\n";
	output<<"add_block(arg1,arg2,arg3,arg4,arg5,arg6,1)\n";
	
	////geostr<<"add_coating",LuaUI::structure_add_coating);
	
	geostr<<"add_cone(\"arg1\",\"arg2\",\"arg3\",\"arg4\",\"arg5\",\"arg6\",\"rad\",2)\n";
	output<<"add_cone(arg1,arg2,arg3,arg4,arg5,arg6,rad,2)\n";
	
	geostr<<"add_conformal_coating(\"arg1\",\"arg3\",1,5)\n";
	output<<"add_conformal_coating(arg1,arg3,1,5)\n";
	
	geostr<<"add_cylinder(\"arg1\",\"arg2\",\"arg3\",\"arg4\",\"arg5\",\"arg6\",\"rad\",3)\n";
	output<<"add_cylinder(arg1,arg2,arg3,arg4,arg5,arg6,rad,3)\n";
	
	////geostr<<"add_ellipsoid",LuaUI::structure_add_ellipsoid);
	//
	geostr<<"add_layer(\"dir\",\"arg1\",\"arg2\",4)\n";
	output<<"add_layer(\"dir\",arg1,arg2,4)\n";
	
	////geostr<<"add_lua_def",LuaUI::structure_add_lua_def);
	////geostr<<"add_mesh",LuaUI::structure_add_mesh);
	////geostr<<"add_sin_layer",LuaUI::structure_add_sin_layer);
	
	geostr<<"add_sphere(\"arg1\",\"arg2\",\"arg3\",\"rad\",5)\n";
	output<<"add_sphere(arg1,arg2,arg3,rad,5)\n";

	std::filesystem::path fname="ageom_sample.ageom";
	std::ofstream script(fname,std::ios::out|std::ios::trunc);

	script<<geostr.str();
	script.close();

	std::string cmp_str=ageom_to_lua(fname);

	if(cmp_str==output.str())
	{
		return 0;
	}
	else
	{
        Plog::print(LogType::FATAL, "Error, unequal strings:\n");
        Plog::print(LogType::FATAL, cmp_str, "\n");
        Plog::print(LogType::FATAL, output.str(), "\n");
		return 1;
	}
}
