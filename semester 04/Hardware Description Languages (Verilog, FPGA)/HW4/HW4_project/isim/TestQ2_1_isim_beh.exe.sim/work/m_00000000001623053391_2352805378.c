/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "E:/rasool/IUT/t4/FPGA/HWs/HW4/HW4_project/Q2_1.v";
static int ng1[] = {0, 0};
static int ng2[] = {32, 0};
static int ng3[] = {1, 0};
static int ng4[] = {2, 0};
static int ng5[] = {3, 0};
static int ng6[] = {4, 0};
static int ng7[] = {5, 0};
static int ng8[] = {6, 0};
static int ng9[] = {7, 0};
static int ng10[] = {8, 0};
static int ng11[] = {9, 0};
static int ng12[] = {10, 0};
static int ng13[] = {11, 0};
static int ng14[] = {12, 0};
static int ng15[] = {13, 0};
static int ng16[] = {14, 0};
static int ng17[] = {15, 0};



static int sp_Correlation_Func(char *t1, char *t2)
{
    char t7[8];
    char t23[8];
    char t33[8];
    char t40[8];
    char t56[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t57;

LAB0:    t0 = 1;
    xsi_set_current_line(61, ng0);

LAB2:    xsi_set_current_line(62, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t1 + 5400);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 6);
    xsi_set_current_line(63, ng0);
    xsi_set_current_line(63, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t1 + 5880);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 6);

LAB3:    t3 = (t1 + 5880);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng2)));
    memset(t7, 0, 8);
    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB5;

LAB4:    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB5;

LAB8:    if (*((unsigned int *)t5) < *((unsigned int *)t6))
        goto LAB6;

LAB7:    t11 = (t7 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t7);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB9;

LAB10:    t0 = 0;

LAB1:    return t0;
LAB5:    t10 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB7;

LAB6:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB9:    xsi_set_current_line(64, ng0);
    t17 = (t1 + 5400);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t1 + 5560);
    t21 = (t20 + 56U);
    t22 = *((char **)t21);
    t24 = (t1 + 5560);
    t25 = (t24 + 72U);
    t26 = *((char **)t25);
    t27 = (t1 + 5880);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    xsi_vlog_generic_get_index_select_value(t23, 1, t22, t26, 2, t29, 6, 2);
    t30 = (t1 + 5720);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t34 = (t1 + 5720);
    t35 = (t34 + 72U);
    t36 = *((char **)t35);
    t37 = (t1 + 5880);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    xsi_vlog_generic_get_index_select_value(t33, 1, t32, t36, 2, t39, 6, 2);
    memset(t40, 0, 8);
    t41 = (t23 + 4);
    t42 = (t33 + 4);
    t43 = *((unsigned int *)t23);
    t44 = *((unsigned int *)t33);
    t45 = (t43 ^ t44);
    t46 = *((unsigned int *)t41);
    t47 = *((unsigned int *)t42);
    t48 = (t46 ^ t47);
    t49 = (t45 | t48);
    t50 = *((unsigned int *)t41);
    t51 = *((unsigned int *)t42);
    t52 = (t50 | t51);
    t53 = (~(t52));
    t54 = (t49 & t53);
    if (t54 != 0)
        goto LAB14;

LAB11:    if (t52 != 0)
        goto LAB13;

LAB12:    *((unsigned int *)t40) = 1;

LAB14:    memset(t56, 0, 8);
    xsi_vlog_unsigned_add(t56, 6, t19, 6, t40, 6);
    t57 = (t1 + 5400);
    xsi_vlogvar_assign_value(t57, t56, 0, 0, 6);
    xsi_set_current_line(63, ng0);
    t3 = (t1 + 5880);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng3)));
    memset(t7, 0, 8);
    xsi_vlog_unsigned_add(t7, 32, t5, 6, t6, 32);
    t8 = (t1 + 5880);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 6);
    goto LAB3;

LAB13:    t55 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t55) = 1;
    goto LAB14;

}

static void Always_26_0(char *t0)
{
    char t26[8];
    char t31[8];
    char t32[8];
    char t52[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    int t41;
    char *t42;
    int t43;
    int t44;
    int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;

LAB0:    t1 = (t0 + 6800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 7120);
    *((int *)t2) = 1;
    t3 = (t0 + 6832);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(26, ng0);

LAB5:    xsi_set_current_line(27, ng0);
    t4 = (t0 + 4360U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(30, ng0);

LAB10:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 1480U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB11:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB13;

LAB12:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng1)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB14;

LAB15:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 1640U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB16:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB18;

LAB17:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng3)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB19;

LAB20:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 1800U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB21:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB23;

LAB22:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng4)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB24;

LAB25:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1960U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB26:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB28;

LAB27:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng5)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB29;

LAB30:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB31:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB33;

LAB32:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng6)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB34;

LAB35:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 2280U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB36:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB38;

LAB37:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng7)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB39;

LAB40:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 2440U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB41:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB43;

LAB42:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng8)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB44;

LAB45:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 2600U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB46:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB48;

LAB47:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng9)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB49;

LAB50:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 2760U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB51:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB53;

LAB52:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng10)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB54;

LAB55:    xsi_set_current_line(40, ng0);
    t2 = (t0 + 2920U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB56:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB58;

LAB57:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng11)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB59;

LAB60:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 3080U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB61:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB63;

LAB62:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng12)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB64;

LAB65:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 3240U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB66:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB68;

LAB67:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng13)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB69;

LAB70:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 3400U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB71:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB73;

LAB72:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng14)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB74;

LAB75:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 3560U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB76:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB78;

LAB77:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng15)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB79;

LAB80:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 3720U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB81:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB83;

LAB82:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 4920);
    t33 = (t0 + 4920);
    t34 = (t33 + 72U);
    t35 = *((char **)t34);
    t36 = (t0 + 4920);
    t37 = (t36 + 64U);
    t38 = *((char **)t37);
    t39 = ((char*)((ng16)));
    xsi_vlog_generic_convert_array_indices(t31, t32, t35, t38, 2, 1, t39, 32, 1);
    t40 = (t31 + 4);
    t6 = *((unsigned int *)t40);
    t41 = (!(t6));
    t42 = (t32 + 4);
    t7 = *((unsigned int *)t42);
    t43 = (!(t7));
    t44 = (t41 && t43);
    if (t44 == 1)
        goto LAB84;

LAB85:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 3880U);
    t3 = *((char **)t2);
    t2 = (t0 + 4040U);
    t4 = *((char **)t2);
    t2 = (t0 + 6608);
    t5 = (t0 + 848);
    t11 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t12 = (t0 + 5560);
    xsi_vlogvar_assign_value(t12, t3, 0, 0, 32);
    t13 = (t0 + 5720);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);

LAB86:    t14 = (t0 + 6704);
    t15 = *((char **)t14);
    t16 = (t15 + 80U);
    t17 = *((char **)t16);
    t18 = (t17 + 272U);
    t19 = *((char **)t18);
    t20 = (t19 + 0U);
    t21 = *((char **)t20);
    t22 = ((int  (*)(char *, char *))t21)(t0, t15);
    if (t22 != 0)
        goto LAB88;

LAB87:    t15 = (t0 + 6704);
    t23 = *((char **)t15);
    t15 = (t0 + 5400);
    t24 = (t15 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 6608);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 5080);
    xsi_vlogvar_assign_value(t30, t26, 0, 0, 6);
    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 4760);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 4, 0LL);
    xsi_set_current_line(48, ng0);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 5240);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB89:    t2 = (t0 + 5240);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t26, 0, 8);
    xsi_vlog_signed_greatereq(t26, 32, t4, 32, t5, 32);
    t11 = (t26 + 4);
    t6 = *((unsigned int *)t11);
    t7 = (~(t6));
    t8 = *((unsigned int *)t26);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB90;

LAB91:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(27, ng0);

LAB9:    xsi_set_current_line(28, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 4760);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 4, 0LL);
    goto LAB8;

LAB13:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB11;
    goto LAB1;

LAB14:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB15;

LAB18:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB16;
    goto LAB1;

LAB19:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB20;

LAB23:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB21;
    goto LAB1;

LAB24:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB25;

LAB28:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB26;
    goto LAB1;

LAB29:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB30;

LAB33:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB31;
    goto LAB1;

LAB34:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB35;

LAB38:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB36;
    goto LAB1;

LAB39:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB40;

LAB43:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB41;
    goto LAB1;

LAB44:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB45;

LAB48:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB46;
    goto LAB1;

LAB49:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB50;

LAB53:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB51;
    goto LAB1;

LAB54:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB55;

LAB58:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB56;
    goto LAB1;

LAB59:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB60;

LAB63:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB61;
    goto LAB1;

LAB64:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB65;

LAB68:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB66;
    goto LAB1;

LAB69:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB70;

LAB73:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB71;
    goto LAB1;

LAB74:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB75;

LAB78:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB76;
    goto LAB1;

LAB79:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB80;

LAB83:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB81;
    goto LAB1;

LAB84:    t8 = *((unsigned int *)t31);
    t9 = *((unsigned int *)t32);
    t45 = (t8 - t9);
    t46 = (t45 + 1);
    xsi_vlogvar_assign_value(t30, t26, 0, *((unsigned int *)t32), t46);
    goto LAB85;

LAB88:    t14 = (t0 + 6800U);
    *((char **)t14) = &&LAB86;
    goto LAB1;

LAB90:    xsi_set_current_line(48, ng0);

LAB92:    xsi_set_current_line(49, ng0);
    t12 = (t0 + 4920);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t0 + 4920);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t18 = (t0 + 4920);
    t19 = (t18 + 64U);
    t20 = *((char **)t19);
    t21 = (t0 + 5240);
    t23 = (t21 + 56U);
    t24 = *((char **)t23);
    xsi_vlog_generic_get_array_select_value(t31, 6, t14, t17, t20, 2, 1, t24, 32, 1);
    t25 = (t0 + 5080);
    t27 = (t25 + 56U);
    t28 = *((char **)t27);
    memset(t32, 0, 8);
    t29 = (t31 + 4);
    if (*((unsigned int *)t29) != 0)
        goto LAB94;

LAB93:    t30 = (t28 + 4);
    if (*((unsigned int *)t30) != 0)
        goto LAB94;

LAB97:    if (*((unsigned int *)t31) < *((unsigned int *)t28))
        goto LAB96;

LAB95:    *((unsigned int *)t32) = 1;

LAB96:    t34 = (t32 + 4);
    t47 = *((unsigned int *)t34);
    t48 = (~(t47));
    t49 = *((unsigned int *)t32);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB98;

LAB99:
LAB100:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 5240);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t26, 0, 8);
    xsi_vlog_signed_minus(t26, 32, t4, 32, t5, 32);
    t11 = (t0 + 5240);
    xsi_vlogvar_assign_value(t11, t26, 0, 0, 32);
    goto LAB89;

LAB94:    t33 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t33) = 1;
    goto LAB96;

LAB98:    xsi_set_current_line(49, ng0);

LAB101:    xsi_set_current_line(50, ng0);
    t35 = (t0 + 4920);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t0 + 4920);
    t39 = (t38 + 72U);
    t40 = *((char **)t39);
    t42 = (t0 + 4920);
    t53 = (t42 + 64U);
    t54 = *((char **)t53);
    t55 = (t0 + 5240);
    t56 = (t55 + 56U);
    t57 = *((char **)t56);
    xsi_vlog_generic_get_array_select_value(t52, 6, t37, t40, t54, 2, 1, t57, 32, 1);
    t58 = (t0 + 5080);
    xsi_vlogvar_assign_value(t58, t52, 0, 0, 6);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 5240);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 4760);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 4, 0LL);
    goto LAB100;

}


extern void work_m_00000000001623053391_2352805378_init()
{
	static char *pe[] = {(void *)Always_26_0};
	static char *se[] = {(void *)sp_Correlation_Func};
	xsi_register_didat("work_m_00000000001623053391_2352805378", "isim/TestQ2_1_isim_beh.exe.sim/work/m_00000000001623053391_2352805378.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
