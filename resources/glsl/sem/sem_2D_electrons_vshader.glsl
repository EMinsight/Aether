/*Copyright 2008-2022 - Lo�c Le Cunff

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.*/

#version 430 core

layout(location=0) in vec4 vpos;
layout(location=1) in vec3 e_color;
layout(location=10) uniform mat4 proj_mat;

out vec4 color_vs;

void main(void) 
{
    gl_Position=proj_mat*vpos;
    
    color_vs.xyz=e_color;
    color_vs.w=1.0;
}
