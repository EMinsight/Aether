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

#ifndef MATH_BESSEL_H_INCLUDED
#define MATH_BESSEL_H_INCLUDED

#include <mathUT.h>

double bessel_J_IM(int nu,double z,double precision=10);
double bessel_K_IM(double nu,double z,double precision=10,double cut=10);

#endif // MATH_BESSEL_H_INCLUDED
