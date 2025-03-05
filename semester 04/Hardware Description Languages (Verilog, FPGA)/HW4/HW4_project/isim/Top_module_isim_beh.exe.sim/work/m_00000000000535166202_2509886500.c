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
static const char *ng0 = "E:/rasool/IUT/t4/FPGA/HWs/HW4/HW4_project/Q1.v";
static int ng1[] = {0, 0, 0, 0};
static int ng2[] = {0, 0};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {0U, 0U};



static int sp_Correlation_Func(char *t1, char *t2)
{
    char t8[8];
    char t20[8];
    char t30[8];
    char t37[16];
    char t38[16];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t39;

LAB0:    t0 = 1;
    xsi_set_current_line(29, ng0);

LAB2:    xsi_set_current_line(30, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t1 + 3616);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 35);
    xsi_set_current_line(31, ng0);
    xsi_set_current_line(31, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t1 + 3776);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);

LAB3:    t3 = (t1 + 3776);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 472);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    xsi_vlog_signed_less(t8, 32, t5, 32, t7, 32);
    t6 = (t8 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t8);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB4;

LAB5:    xsi_set_current_line(33, ng0);
    t3 = (t1 + 3616);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 3136);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 35);
    t0 = 0;

LAB1:    return t0;
LAB4:    xsi_set_current_line(32, ng0);
    t14 = (t1 + 3616);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 3296);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t21 = (t1 + 3296);
    t22 = (t21 + 72U);
    t23 = *((char **)t22);
    t24 = (t1 + 3776);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_index_select_value(t20, 1, t19, t23, 2, t26, 32, 1);
    t27 = (t1 + 3456);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t31 = (t1 + 3456);
    t32 = (t31 + 72U);
    t33 = *((char **)t32);
    t34 = (t1 + 3776);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    xsi_vlog_generic_get_index_select_value(t30, 1, t29, t33, 2, t36, 32, 1);
    xsi_vlog_unsigned_equal(t37, 35, t20, 1, t30, 1);
    xsi_vlog_unsigned_add(t38, 35, t16, 35, t37, 35);
    t39 = (t1 + 3616);
    xsi_vlogvar_assign_value(t39, t38, 0, 0, 35);
    xsi_set_current_line(31, ng0);
    t3 = (t1 + 3776);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_signed_add(t8, 32, t5, 32, t6, 32);
    t7 = (t1 + 3776);
    xsi_vlogvar_assign_value(t7, t8, 0, 0, 32);
    goto LAB3;

}

static void Cont_22_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t21[8];
    char t25[8];
    char t43[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t22;
    char *t23;
    char *t24;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t44;
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
    unsigned int t55;
    unsigned int t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    unsigned int t69;
    unsigned int t70;
    char *t71;

LAB0:    t1 = (t0 + 4696U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(22, ng0);
    t2 = (t0 + 2256U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t17 = *((unsigned int *)t4);
    t18 = (~(t17));
    t19 = *((unsigned int *)t12);
    t20 = (t18 || t19);
    if (t20 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t21, 8);

LAB16:    t58 = (t0 + 5360);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    t61 = (t60 + 56U);
    t62 = *((char **)t61);
    memset(t62, 0, 8);
    t63 = 3U;
    t64 = t63;
    t65 = (t3 + 4);
    t66 = *((unsigned int *)t3);
    t63 = (t63 & t66);
    t67 = *((unsigned int *)t65);
    t64 = (t64 & t67);
    t68 = (t62 + 4);
    t69 = *((unsigned int *)t62);
    *((unsigned int *)t62) = (t69 | t63);
    t70 = *((unsigned int *)t68);
    *((unsigned int *)t68) = (t70 | t64);
    xsi_driver_vfirst_trans(t58, 0, 1);
    t71 = (t0 + 5264);
    *((int *)t71) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = ((char*)((ng4)));
    goto LAB9;

LAB10:    t22 = (t0 + 1616U);
    t23 = *((char **)t22);
    t22 = (t0 + 1936U);
    t24 = *((char **)t22);
    memset(t25, 0, 8);
    t22 = (t23 + 4);
    t26 = (t24 + 4);
    t27 = *((unsigned int *)t23);
    t28 = *((unsigned int *)t24);
    t29 = (t27 ^ t28);
    t30 = *((unsigned int *)t22);
    t31 = *((unsigned int *)t26);
    t32 = (t30 ^ t31);
    t33 = (t29 | t32);
    t34 = *((unsigned int *)t22);
    t35 = *((unsigned int *)t26);
    t36 = (t34 | t35);
    t37 = (~(t36));
    t38 = (t33 & t37);
    if (t38 != 0)
        goto LAB20;

LAB17:    if (t36 != 0)
        goto LAB19;

LAB18:    *((unsigned int *)t25) = 1;

LAB20:    t40 = (t0 + 1776U);
    t41 = *((char **)t40);
    t40 = (t0 + 1936U);
    t42 = *((char **)t40);
    memset(t43, 0, 8);
    t40 = (t41 + 4);
    t44 = (t42 + 4);
    t45 = *((unsigned int *)t41);
    t46 = *((unsigned int *)t42);
    t47 = (t45 ^ t46);
    t48 = *((unsigned int *)t40);
    t49 = *((unsigned int *)t44);
    t50 = (t48 ^ t49);
    t51 = (t47 | t50);
    t52 = *((unsigned int *)t40);
    t53 = *((unsigned int *)t44);
    t54 = (t52 | t53);
    t55 = (~(t54));
    t56 = (t51 & t55);
    if (t56 != 0)
        goto LAB24;

LAB21:    if (t54 != 0)
        goto LAB23;

LAB22:    *((unsigned int *)t43) = 1;

LAB24:    xsi_vlogtype_concat(t21, 2, 2, 2U, t43, 1, t25, 1);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 2, t16, 2, t21, 2);
    goto LAB16;

LAB14:    memcpy(t3, t16, 8);
    goto LAB16;

LAB19:    t39 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB20;

LAB23:    t57 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t57) = 1;
    goto LAB24;

}

static void Always_36_1(char *t0)
{
    char t29[16];
    char t33[16];
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
    char *t22;
    char *t23;
    char *t24;
    int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t30;
    char *t31;
    char *t32;
    char *t34;

LAB0:    t1 = (t0 + 4944U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 5280);
    *((int *)t2) = 1;
    t3 = (t0 + 4976);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(36, ng0);

LAB5:    xsi_set_current_line(37, ng0);
    t4 = (t0 + 2256U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(41, ng0);

LAB10:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2816);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1616U);
    t11 = *((char **)t5);
    t5 = (t0 + 1936U);
    t12 = *((char **)t5);
    t5 = (t0 + 4752);
    t13 = (t0 + 984);
    t14 = xsi_create_subprogram_invocation(t5, 0, t0, t13, 0, 0);
    t15 = (t0 + 3296);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 32);
    t16 = (t0 + 3456);
    xsi_vlogvar_assign_value(t16, t12, 0, 0, 32);

LAB11:    t17 = (t0 + 4848);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);
    if (t25 != 0)
        goto LAB13;

LAB12:    t18 = (t0 + 4848);
    t26 = *((char **)t18);
    t18 = (t0 + 3136);
    t27 = (t18 + 56U);
    t28 = *((char **)t27);
    memcpy(t29, t28, 16);
    t30 = (t0 + 984);
    t31 = (t0 + 4752);
    t32 = 0;
    xsi_delete_subprogram_invocation(t30, t26, t0, t31, t32);
    xsi_vlog_unsigned_add(t33, 35, t4, 35, t29, 35);
    t34 = (t0 + 2816);
    xsi_vlogvar_wait_assign_value(t34, t33, 0, 0, 35, 0LL);
    xsi_set_current_line(43, ng0);
    t2 = (t0 + 2976);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 1776U);
    t11 = *((char **)t5);
    t5 = (t0 + 1936U);
    t12 = *((char **)t5);
    t5 = (t0 + 4752);
    t13 = (t0 + 984);
    t14 = xsi_create_subprogram_invocation(t5, 0, t0, t13, 0, 0);
    t15 = (t0 + 3296);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 32);
    t16 = (t0 + 3456);
    xsi_vlogvar_assign_value(t16, t12, 0, 0, 32);

LAB14:    t17 = (t0 + 4848);
    t18 = *((char **)t17);
    t19 = (t18 + 80U);
    t20 = *((char **)t19);
    t21 = (t20 + 272U);
    t22 = *((char **)t21);
    t23 = (t22 + 0U);
    t24 = *((char **)t23);
    t25 = ((int  (*)(char *, char *))t24)(t0, t18);
    if (t25 != 0)
        goto LAB16;

LAB15:    t18 = (t0 + 4848);
    t26 = *((char **)t18);
    t18 = (t0 + 3136);
    t27 = (t18 + 56U);
    t28 = *((char **)t27);
    memcpy(t29, t28, 16);
    t30 = (t0 + 984);
    t31 = (t0 + 4752);
    t32 = 0;
    xsi_delete_subprogram_invocation(t30, t26, t0, t31, t32);
    xsi_vlog_unsigned_add(t33, 35, t4, 35, t29, 35);
    t34 = (t0 + 2976);
    xsi_vlogvar_wait_assign_value(t34, t33, 0, 0, 35, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(37, ng0);

LAB9:    xsi_set_current_line(38, ng0);
    t11 = ((char*)((ng1)));
    t12 = (t0 + 2816);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 35, 0LL);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2976);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 35, 0LL);
    goto LAB8;

LAB13:    t17 = (t0 + 4944U);
    *((char **)t17) = &&LAB11;
    goto LAB1;

LAB16:    t17 = (t0 + 4944U);
    *((char **)t17) = &&LAB14;
    goto LAB1;

}


extern void work_m_00000000000535166202_2509886500_init()
{
	static char *pe[] = {(void *)Cont_22_0,(void *)Always_36_1};
	static char *se[] = {(void *)sp_Correlation_Func};
	xsi_register_didat("work_m_00000000000535166202_2509886500", "isim/Top_module_isim_beh.exe.sim/work/m_00000000000535166202_2509886500.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
