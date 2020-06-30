#include <stdio.h>
#include "cpp2c_inheritance_defs.h"




void g_doMaterials_v()
{
    const char* const g_material_names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("\n--- Start doMaterials() ---\n\n");

    Materials mat;
    printf("Size of Materials: %lu\n", sizeof(mat));
    printf("Size of mat: %lu\n", sizeof(Materials));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(material_t));
    struct MatTest { Materials mat; material_t mat_t; };
    printf("Size of Materials + Material_t: %lu\n", sizeof(struct MatTest));

    material_t mat1;
    mat1.material=OTHER;
    printf("Material created, set to %s\n", g_material_names[mat1.material]);
    material_t mat2;
    mat2.material=METAL;
    printf("Material created, set to %s\n", g_material_names[mat2.material]);
    printf("\n--- End doMaterials() ---\n\n");
}

void g_doPhysicalBox_v()
{
    const char* const g_material_names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    physical_box pb1;
    physical_box pb2;
    physical_box pb3;
    physical_box pb4;
    printf("\n--- Start doPhysicalBox() ---\n\n");

//    PhysicalBox pb1(8, 6, 4, Materials::PLASTIC);
    material_t mathelp;
    mathelp.material=PLASTIC;
    printf("Material created, set to %s\n", g_material_names[mathelp.material]);
    physical_box_init_dddt(&pb1,8,6,4,mathelp);
    material_t mathelp2;
    mathelp2.material=WOOD;
    printf("Material created, set to %s\n", g_material_names[mathelp2.material]);
    pysical_box_init_t(&pb2,mathelp2);
    physical_box_init_ddd(&pb3,7,7,7);
////    PhysicalBox pb2(Materials::WOOD);
////    PhysicalBox pb3(7, 7, 7);
//
    printf("\npb4 is copy-constructed from pb1\n");
    pb4 = pb3;
    pysical_box_print(&pb4);
    pysical_box_print(&pb1);
    printf("pb4 %s pb1\n", pb4.box_p.length==pb1.box_p.length && pb4.box_p.width==pb1.box_p.width && pb4.box_p.height==pb1.box_p.height && pb1.material.material==pb4.material.material? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    pysical_box_print(&pb4);
    pysical_box_print(&pb3);
    printf("pb4 %s pb3\n", pb4.box_p.length==pb3.box_p.length && pb4.box_p.width==pb3.box_p.width && pb4.box_p.height==pb3.box_p.height &&  pb3.material.material==pb4.material.material ? "equals" : "does not equal");


    printf("\n--- End doPhysicalBox() ---\n\n");
    pysical_box_destroy(&pb1);
    pysical_box_destroy(&pb2);
    pysical_box_destroy(&pb3);
    pysical_box_destroy(&pb4);
}

void g_doWeightBox_v()
{
    printf("\n--- Start doWeightBox() ---\n\n");

    weight_box pw1;
    weight_box pw2;
    weight_box pw3;
    weight_box pw4;
    weight_box_init_dddd(&pw1,8,6,4,25);
    weight_box_init_dddd(&pw2,1,2,3,0.0);
    weight_box_init_dddd(&pw3,10,20,30,15);

    printf("\npw4 is copy-constructed from pw1\n");
    weight_box_copy_box(&pw4,&pw1);
    weight_box_print_v(&pw4);
    weight_box_print_v(&pw1);
    printf("pw4 %s pw1\n", pw4.box_w.length==pw1.box_w.length && pw4.box_w.width==pw1.box_w.width && pw4.box_w.height==pw1.box_w.height && pw4.weight==pw1.weight ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    weight_boxptr_assignment_wb(&pw4,&pw3);
    weight_box_print_v(&pw4);
    weight_box_print_v(&pw3);
    printf("pw4 %s pw1\n", pw4.box_w.length==pw3.box_w.length && pw4.box_w.width==pw3.box_w.width && pw4.box_w.height==pw3.box_w.height && pw4.weight==pw3.weight ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
    weight_box_destroy(&pw1);
    weight_box_destroy(&pw2);
    weight_box_destroy(&pw3);
    weight_box_destroy(&pw4);
}





int main()
{
    printf("\n--- Start main() ---\n\n");

    g_doMaterials_v();
    g_doPhysicalBox_v();

    g_doWeightBox_v();

    printf("\n--- End main() ---\n\n");
    return 1;
}
