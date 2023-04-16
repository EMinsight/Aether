/*Copyright 2008-2023 - Lo�c Le Cunff

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.*/

#ifndef GUI_MATERIAL_H_INCLUDED
#define GUI_MATERIAL_H_INCLUDED

#include <gui.h>
#include <gui_graph.h>
#include <gui_material_editor.h>
#include <gui_material_library.h>
#include <gui_rsc.h>
//#include <phys_tools.h>

wxDECLARE_EVENT(EVT_MAT_SELECTOR,wxCommandEvent);
wxDECLARE_EVENT(EVT_MINIMAT_SELECTOR,wxCommandEvent);

class MaterialSelector;
class MaterialsManager;

class MaterialSelector: public wxPanel
{
    public:
        MatType mat_type;
        double const_index,weight;
        
        GUI::Material *const_model;
        GUI::Material *library_model;
        
        wxChoice *mat_type_ctrl;
        wxButton *load_btn;
        wxButton *inspect_btn;
        wxTextCtrl *mat_txt;
        
        // Effective Material
        
        GUI::Material *eff_material;
        wxPanel *eff_panel;
        wxChoice *eff_type;
        wxBoxSizer *eff_sizer;
        MaterialSelector *eff_mat_1_selector,
                         *eff_mat_2_selector;
        NamedTextCtrl<double> *eff_weight;
        
        // Custom
        
        MaterialEditor *custom_editor;
        
        // Validator
        
        bool (*accept_material)(Material*);
        
        MaterialSelector(wxWindow *parent,std::string name,bool no_box=false,
                         bool (*validator)(Material*)=&default_material_validator);
        MaterialSelector(wxWindow *parent,std::string name,bool no_box,GUI::Material *material,
                         bool (*validator)(Material*)=&default_material_validator);
        void MaterialSelector_EffPanel(wxWindow *parent);
        void MaterialSelector_CustomPanel(wxWindow *parent);
        ~MaterialSelector();
        
        void allocate_effective_materials();
        void allocate_effective_materials(GUI::Material *eff_mat_1,
                                          GUI::Material *eff_mat_2);
//        virtual bool accept_material(Material *material);
        void const_index_event(wxCommandEvent &event);
        void evt_const_index_focus(wxFocusEvent &event);
        void evt_custom_material(wxCommandEvent &event);
        void evt_effective_material(wxCommandEvent &event);
        void evt_inspect(wxCommandEvent &event);
        void evt_load(wxCommandEvent &event);
        void evt_mat_type(wxCommandEvent &event);
        Imdouble get_eps(double w);
        int get_effective_material_type();
        std::string get_lua();
        GUI::Material* get_material();
        wxString get_name();
        wxString get_title();
        MatType get_type();
        double get_lambda_validity_min();
        double get_lambda_validity_max();
        double get_weight();
        void layout_const();
        void layout_custom();
        void layout_effective();
        void layout_library();
        void operator = (MaterialSelector const &selector);
        void set_const_model(double n);
        void throw_event();
};

class MiniMaterialSelector: public wxPanel
{
    public:
        MatType mat_type;
        wxGenericStaticBitmap *mat_bmp;
        wxStaticText *mat_txt;
        wxTextCtrl *mat_name;
        wxButton *edit_btn;
        NamedTextCtrl<double> *eff_weight;
        
        GUI::Material material;
        
        MiniMaterialSelector(wxWindow *parent,
                             GUI::Material *material,
                             std::string const &name="");
        
        MiniMaterialSelector(wxWindow *parent,
                             std::string const &name="",
                             std::filesystem::path const &script_fname="");
        
        void copy_material(MiniMaterialSelector *mat);
        void evt_edit(wxCommandEvent &event);
        void evt_weight(wxCommandEvent &event);
        Imdouble get_eps(double w);
        wxString get_lua();
        Imdouble get_n(double w);
        [[deprecated]]GUI::Material& get_material();
        void set_material(std::filesystem::path const &script_fname);
        void update_label();
};

class MaterialExplorer: public BaseFrame
{
    public:
        unsigned int Np;
        double lambda_min,lambda_max;
        
        std::vector<double> lambda,disp_lambda,disp_real,disp_imag;
        
        wxChoice *disp_choice;
        
        MaterialSelector *mat_selector;
        SpectrumSelector *sp_selector;
        
        Graph *mat_graph;
        
        MaterialExplorer(wxString const &title);
        MaterialExplorer(double lambda_min,double lambda_max,int Np,MaterialSelector *selector=nullptr);
        
        void disp_choice_event(wxCommandEvent &event);
        void export_event(wxCommandEvent &event);
        void material_selector_event(wxCommandEvent &event);
        void spectrum_selector_event(wxCommandEvent &event);
        void recompute_model();
};

class MaterialsManager: public BaseFrame
{
    public:
        unsigned int Np;
        double lambda_min,lambda_max;
        
        std::vector<double> lambda,disp_lambda,disp_real,disp_imag;
        
        // Controls
        
        NamedTextCtrl<std::string> *material_path;
        
        wxScrolledWindow *ctrl_panel;
        
        MaterialEditor *editor;
        
        // Display
        
        Graph *mat_graph;
        SpectrumSelector *sp_selector;
        wxChoice *disp_choice;
        
        MaterialsManager(wxString const &title);
        ~MaterialsManager();
        
        void MaterialsManager_Controls();
        void MaterialsManager_Display(wxPanel *display_panel);
        
        void evt_display_choice(wxCommandEvent &event);
        void evt_material_editor_model(wxCommandEvent &event);
        void evt_material_editor_spectrum(wxCommandEvent &event);
//        void evt_material_selector(wxCommandEvent &event);
        void evt_menu(wxCommandEvent &event);
        void evt_menu_exit();
        void evt_menu_load();
        void evt_menu_new();
        void evt_menu_save();
        void evt_menu_save_as();
        void evt_spectrum_selector(wxCommandEvent &event);
//        void export_event(wxCommandEvent &event);
        void recompute_model();
};

#endif // GUI_MATERIAL_H_INCLUDED
