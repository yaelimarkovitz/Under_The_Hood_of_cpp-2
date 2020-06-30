#include <stdio.h>
#include "cpp2c_inheritance_defs.h"


// PhysicalBox Defs ////////////
//PhysicalBox::PhysicalBox(double l, double w, double h)
//:   Box(l, w, h)
//{
//printp();
//}
void physical_box_init_ddd(physical_boxptr this,double l, double w, double h){
    box_init_ddd(&this->box_p,l,w,h);
    material_t tmp;
    tmp.material = OTHER;
    printf("Material created, set to %s\n", "Other");
    this->material = tmp;
    pysical_box_print(this);

}
//PhysicalBox::PhysicalBox(double l, double w, double h, Materials::Types t)
//:   Box(l, w, h)
//,   material(t)
//        {
//                printp();
//        }
//
void physical_box_init_dddt(physical_boxptr this,double l, double w, double h,material_t t){
    box_init_ddd(&this->box_p,l,w,h);
    this->material = t;
    pysical_box_print(this);
}
//PhysicalBox::PhysicalBox(Materials::Types t)
//:   material(t)
//        {
//                printp();
//        }
//
void pysical_box_init_t(physical_boxptr this,material_t t){
    box_init_ddd(&this->box_p,1,1,1);
    this->material = t;
    pysical_box_print(this);
}
//PhysicalBox::~PhysicalBox()
//{
//    printf("PhysicalBox dtor, %f x %f x %f, %s; ", getLength(), getWidth(), getHeight(), material.name());
//}
void pysical_box_destroy(physical_boxptr this){
    const char* const g_material_names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->box_p.length, this->box_p.width, this->box_p.height, g_material_names[this->material.material]);
    box_destroy(&this->box_p);
}
//void PhysicalBox::printp() const
//{
//printf("PhysicalBox, made of %s; ", material.name());
//print();
//}
void pysical_box_print(physical_boxptr this){
    const char* const g_material_names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox, made of %s;  ",g_material_names[this->material.material]);
    box_print_vC(&this->box_p);
}

/// WeightBox Defs ////////////
//WeightBox::WeightBox(double l, double w, double h, double wgt)
//:   Box(l, w, h)
//,   weight(wgt)
//{
//    printw();
//}
void weight_box_init_dddd(weight_boxptr this,double l, double w, double h, double wgt){
    box_init_ddd(&this->box_w,l,w,h);
    this->weight=wgt;
    weight_box_print_v(this);
}
//WeightBox::WeightBox(const WeightBox& other)
//:   weight(other.weight)
//{
//    printw();
//}
void weight_box_copy_box(weight_boxptr this, const weight_boxptr other){
    box_init_ddd(&this->box_w,1,1,1);
    this->weight = other->weight;
    weight_box_print_v(this);
}
//void WeightBox::printw() const
//{
//    printf("WeightBox, weight: %f; ", weight);
//    print();
//}
void weight_box_print_v(weight_boxptr this){
    printf("WeightBox, weight: %f; ", this->weight);
    box_print_vC(&this->box_w);
}
//WeightBox::~WeightBox()
//{
//    printf("Destructing WeightBox; ");
//    printw();
//}
void weight_box_destroy(weight_boxptr this){
    printf("Destructing WeightBox; ");
    weight_box_print_v(this);
    box_destroy(&this->box_w);
}
//WeightBox& WeightBox::operator=(const WeightBox& other)
//{
//    weight = other.weight;
//    return *this;
//}
weight_boxptr weight_boxptr_assignment_wb(weight_boxptr this ,const weight_boxptr other){
    this->weight = other->weight;
}


