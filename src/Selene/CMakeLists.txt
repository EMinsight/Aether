set(selene_src sel_analysis.cpp
			   sel_irf.cpp
			   sel_light.cpp
			   sel_mesh.cpp
			   sel_obj.cpp
			   sel_obj_surface.cpp
			   sel_obj_volume.cpp
			   selene.cpp
			   selene_rays.cpp
			   primitives/sel_obj_box.cpp
			   primitives/sel_obj_cone.cpp
			   primitives/sel_obj_conic.cpp
			   primitives/sel_obj_cylinder.cpp
			   primitives/sel_obj_disk.cpp
			   primitives/sel_obj_lens.cpp
			   primitives/sel_obj_mesh.cpp
			   primitives/sel_obj_parabola.cpp
			   primitives/sel_obj_polynomial.cpp
			   primitives/sel_obj_rectangle.cpp
			   primitives/sel_obj_sphere.cpp
			   primitives/sel_obj_spherical_patch.cpp)
			 
set(selene_headers selene.h
                   selene_mesh.h
                   selene_rays.h
                   selene_primitives.h)

add_library(selene_core STATIC ${selene_src} ${selene_headers})
target_include_directories(selene_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(selene_core PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
target_link_libraries(selene_core common_lib multilayers)