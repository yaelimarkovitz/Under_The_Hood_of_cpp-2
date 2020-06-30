#ifndef __CPP2C_INHERITANCE_DEFS_H__
#define __CPP2C_INHERITANCE_DEFS_H__

#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

//// Materials ////////////
typedef enum Types
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;
//struct Materials
//{
//    enum Types
//    {
//        PLASTIC,
//        METAL,
//        WOOD,
//        PAPER,
//        OTHER
//    };
//
//    static const char* getName(Types type)
//    {
//        const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
//        return names[type];
//    }
//};
typedef struct Materials{
    char c;
}Materials;

// struct Material_t:public Materials
//{
////    Material_t(Types mat = OTHER): material(mat) { printf("Material created, set to %s\n", name()); }
////    const char* name() const { return getName(material); }
//    Types material;
//}
typedef struct material_t{
    Types material;
}material_t;
//// PhysicalBox ////////////

//class PhysicalBox: public Box
//{
//public:
//    PhysicalBox(double l, double w, double h);
//    PhysicalBox(double l, double w, double h, Materials::Types t);
//    PhysicalBox(Materials::Types t);
//    ~PhysicalBox();
//
//    Materials::Types getMaterial() const;
//    void printp() const;
//
//private:
//    Material_t material;
//};
typedef struct physical_box{
    box box_p;
    material_t material;
}physical_box;
typedef physical_box* physical_boxptr;
void physical_box_init_ddd(physical_boxptr this,double l, double w, double h);
void physical_box_init_dddt(physical_boxptr this,double l, double w, double h,material_t t);
void pysical_box_init_t(physical_boxptr this,material_t t);
void pysical_box_print(physical_boxptr this);
void pysical_box_destroy(physical_boxptr this);

//class WeightBox: public Box
//{
//public:
//    WeightBox(double l, double w, double h, double wgt = 0.0);
//    WeightBox(const WeightBox& other);
//    ~WeightBox();
//
//    WeightBox& operator=(const WeightBox& other);
//
//    double getWeight() const;
//    void printw() const;
//
//private:
//    double weight;
//};

typedef struct weight_box{
    box box_w;
    double  weight;
}weight_box;
typedef weight_box* weight_boxptr;
void weight_box_init_dddd(weight_boxptr this,double l, double w, double h, double wgt);
void weight_box_copy_box(weight_boxptr this, const weight_boxptr other);
void weight_box_print_v(weight_boxptr this);
void weight_box_destroy(weight_boxptr this);
weight_boxptr weight_boxptr_assignment_wb(weight_boxptr this ,const weight_boxptr other);












#endif // __CPP2C_INHERITANCE_DEFS_H__


