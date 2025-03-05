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
static const char *ng0 = "E:/rasool/IUT/t4/FPGA/HWs/HW2/Project/Q3.v";
static int ng1[] = {0, 0};
static int ng2[] = {4, 0};
static unsigned int ng3[] = {0U, 0U};
static unsigned int ng4[] = {23U, 0U};
static int ng5[] = {1, 0};
static unsigned int ng6[] = {1U, 0U};
static unsigned int ng7[] = {10U, 0U};
static unsigned int ng8[] = {2U, 0U};
static unsigned int ng9[] = {21U, 0U};
static unsigned int ng10[] = {3U, 0U};
static unsigned int ng11[] = {20U, 0U};



static void Always_11_0(char *t0)
{
    char t4[8];
    char t7[8];
    char t23[8];
    char t34[8];
    char *t1;
    char *t2;
    char *t3;
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
    unsigned int t17;
    char *t18;
    char *t19;
    int t20;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t57;

LAB0:    t1 = (t0 + 3488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(11, ng0);
    t2 = (t0 + 3808);
    *((int *)t2) = 1;
    t3 = (t0 + 3520);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(11, ng0);

LAB5:    xsi_set_current_line(12, ng0);
    t5 = (t0 + 1368U);
    t6 = *((char **)t5);
    t5 = (t0 + 2568);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    memset(t7, 0, 8);
    t10 = (t7 + 4);
    t11 = (t9 + 4);
    t12 = *((unsigned int *)t9);
    t13 = (t12 >> 0);
    *((unsigned int *)t7) = t13;
    t14 = *((unsigned int *)t11);
    t15 = (t14 >> 0);
    *((unsigned int *)t10) = t15;
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t16 & 15U);
    t17 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t17 & 15U);
    xsi_vlogtype_concat(t4, 5, 5, 2U, t7, 4, t6, 1);
    t18 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t18, t4, 0, 0, 5, 0LL);
    xsi_set_current_line(13, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(16, ng0);
    t2 = (t0 + 1208U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t12 = *((unsigned int *)t2);
    t13 = (~(t12));
    t14 = *((unsigned int *)t3);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(20, ng0);

LAB10:    xsi_set_current_line(21, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng2)));
    memset(t4, 0, 8);
    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB12;

LAB11:    t9 = (t6 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB12;

LAB15:    if (*((unsigned int *)t5) < *((unsigned int *)t6))
        goto LAB14;

LAB13:    *((unsigned int *)t4) = 1;

LAB14:    t11 = (t4 + 4);
    t12 = *((unsigned int *)t11);
    t13 = (~(t12));
    t14 = *((unsigned int *)t4);
    t15 = (t14 & t13);
    t16 = (t15 != 0);
    if (t16 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(45, ng0);
    t2 = (t0 + 2248);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_add(t4, 32, t5, 4, t6, 32);
    t8 = (t0 + 2248);
    xsi_vlogvar_assign_value(t8, t4, 0, 0, 4);

LAB18:
LAB8:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 2, 0LL);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = (t0 + 1528U);
    t8 = *((char **)t6);
    memset(t4, 0, 8);
    t6 = (t5 + 4);
    t9 = (t8 + 4);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t9);
    t17 = (t15 ^ t16);
    t28 = (t14 | t17);
    t29 = *((unsigned int *)t6);
    t30 = *((unsigned int *)t9);
    t31 = (t29 | t30);
    t32 = (~(t31));
    t37 = (t28 & t32);
    if (t37 != 0)
        goto LAB62;

LAB61:    if (t31 != 0)
        goto LAB63;

LAB64:    t11 = (t4 + 4);
    t38 = *((unsigned int *)t11);
    t39 = (~(t38));
    t40 = *((unsigned int *)t4);
    t41 = (t40 & t39);
    t42 = (t41 != 0);
    if (t42 > 0)
        goto LAB65;

LAB66:
LAB67:    goto LAB2;

LAB6:    xsi_set_current_line(16, ng0);

LAB9:    xsi_set_current_line(17, ng0);
    t5 = ((char*)((ng1)));
    t6 = (t0 + 2248);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 4);
    xsi_set_current_line(18, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    goto LAB8;

LAB12:    t10 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB14;

LAB16:    xsi_set_current_line(22, ng0);
    t18 = (t0 + 1528U);
    t19 = *((char **)t18);

LAB19:    t18 = ((char*)((ng3)));
    t20 = xsi_vlog_unsigned_case_compare(t19, 2, t18, 2);
    if (t20 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng6)));
    t20 = xsi_vlog_unsigned_case_compare(t19, 2, t2, 2);
    if (t20 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng8)));
    t20 = xsi_vlog_unsigned_case_compare(t19, 2, t2, 2);
    if (t20 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng10)));
    t20 = xsi_vlog_unsigned_case_compare(t19, 2, t2, 2);
    if (t20 == 1)
        goto LAB26;

LAB27:
LAB28:    goto LAB18;

LAB20:    xsi_set_current_line(24, ng0);
    t21 = (t0 + 1368U);
    t22 = *((char **)t21);
    t21 = (t0 + 2568);
    t24 = (t21 + 56U);
    t25 = *((char **)t24);
    memset(t23, 0, 8);
    t26 = (t23 + 4);
    t27 = (t25 + 4);
    t17 = *((unsigned int *)t25);
    t28 = (t17 >> 0);
    *((unsigned int *)t23) = t28;
    t29 = *((unsigned int *)t27);
    t30 = (t29 >> 0);
    *((unsigned int *)t26) = t30;
    t31 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t31 & 15U);
    t32 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t32 & 15U);
    xsi_vlogtype_concat(t7, 5, 5, 2U, t23, 4, t22, 1);
    t33 = ((char*)((ng4)));
    memset(t34, 0, 8);
    t35 = (t7 + 4);
    t36 = (t33 + 4);
    t37 = *((unsigned int *)t7);
    t38 = *((unsigned int *)t33);
    t39 = (t37 ^ t38);
    t40 = *((unsigned int *)t35);
    t41 = *((unsigned int *)t36);
    t42 = (t40 ^ t41);
    t43 = (t39 | t42);
    t44 = *((unsigned int *)t35);
    t45 = *((unsigned int *)t36);
    t46 = (t44 | t45);
    t47 = (~(t46));
    t48 = (t43 & t47);
    if (t48 != 0)
        goto LAB32;

LAB29:    if (t46 != 0)
        goto LAB31;

LAB30:    *((unsigned int *)t34) = 1;

LAB32:    t50 = (t34 + 4);
    t51 = *((unsigned int *)t50);
    t52 = (~(t51));
    t53 = *((unsigned int *)t34);
    t54 = (t53 & t52);
    t55 = (t54 != 0);
    if (t55 > 0)
        goto LAB33;

LAB34:
LAB35:    goto LAB28;

LAB22:    xsi_set_current_line(29, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    t3 = (t0 + 2568);
    t6 = (t3 + 56U);
    t8 = *((char **)t6);
    memset(t7, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    *((unsigned int *)t7) = t13;
    t14 = *((unsigned int *)t10);
    t15 = (t14 >> 0);
    *((unsigned int *)t9) = t15;
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t16 & 15U);
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 15U);
    xsi_vlogtype_concat(t4, 5, 5, 2U, t7, 4, t5, 1);
    t11 = ((char*)((ng7)));
    memset(t23, 0, 8);
    t18 = (t4 + 4);
    t21 = (t11 + 4);
    t28 = *((unsigned int *)t4);
    t29 = *((unsigned int *)t11);
    t30 = (t28 ^ t29);
    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t21);
    t37 = (t31 ^ t32);
    t38 = (t30 | t37);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t21);
    t41 = (t39 | t40);
    t42 = (~(t41));
    t43 = (t38 & t42);
    if (t43 != 0)
        goto LAB40;

LAB37:    if (t41 != 0)
        goto LAB39;

LAB38:    *((unsigned int *)t23) = 1;

LAB40:    t24 = (t23 + 4);
    t44 = *((unsigned int *)t24);
    t45 = (~(t44));
    t46 = *((unsigned int *)t23);
    t47 = (t46 & t45);
    t48 = (t47 != 0);
    if (t48 > 0)
        goto LAB41;

LAB42:
LAB43:    goto LAB28;

LAB24:    xsi_set_current_line(34, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    t3 = (t0 + 2568);
    t6 = (t3 + 56U);
    t8 = *((char **)t6);
    memset(t7, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    *((unsigned int *)t7) = t13;
    t14 = *((unsigned int *)t10);
    t15 = (t14 >> 0);
    *((unsigned int *)t9) = t15;
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t16 & 15U);
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 15U);
    xsi_vlogtype_concat(t4, 5, 5, 2U, t7, 4, t5, 1);
    t11 = ((char*)((ng9)));
    memset(t23, 0, 8);
    t18 = (t4 + 4);
    t21 = (t11 + 4);
    t28 = *((unsigned int *)t4);
    t29 = *((unsigned int *)t11);
    t30 = (t28 ^ t29);
    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t21);
    t37 = (t31 ^ t32);
    t38 = (t30 | t37);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t21);
    t41 = (t39 | t40);
    t42 = (~(t41));
    t43 = (t38 & t42);
    if (t43 != 0)
        goto LAB48;

LAB45:    if (t41 != 0)
        goto LAB47;

LAB46:    *((unsigned int *)t23) = 1;

LAB48:    t24 = (t23 + 4);
    t44 = *((unsigned int *)t24);
    t45 = (~(t44));
    t46 = *((unsigned int *)t23);
    t47 = (t46 & t45);
    t48 = (t47 != 0);
    if (t48 > 0)
        goto LAB49;

LAB50:
LAB51:    goto LAB28;

LAB26:    xsi_set_current_line(39, ng0);
    t3 = (t0 + 1368U);
    t5 = *((char **)t3);
    t3 = (t0 + 2568);
    t6 = (t3 + 56U);
    t8 = *((char **)t6);
    memset(t7, 0, 8);
    t9 = (t7 + 4);
    t10 = (t8 + 4);
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    *((unsigned int *)t7) = t13;
    t14 = *((unsigned int *)t10);
    t15 = (t14 >> 0);
    *((unsigned int *)t9) = t15;
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t16 & 15U);
    t17 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t17 & 15U);
    xsi_vlogtype_concat(t4, 5, 5, 2U, t7, 4, t5, 1);
    t11 = ((char*)((ng11)));
    memset(t23, 0, 8);
    t18 = (t4 + 4);
    t21 = (t11 + 4);
    t28 = *((unsigned int *)t4);
    t29 = *((unsigned int *)t11);
    t30 = (t28 ^ t29);
    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t21);
    t37 = (t31 ^ t32);
    t38 = (t30 | t37);
    t39 = *((unsigned int *)t18);
    t40 = *((unsigned int *)t21);
    t41 = (t39 | t40);
    t42 = (~(t41));
    t43 = (t38 & t42);
    if (t43 != 0)
        goto LAB56;

LAB53:    if (t41 != 0)
        goto LAB55;

LAB54:    *((unsigned int *)t23) = 1;

LAB56:    t24 = (t23 + 4);
    t44 = *((unsigned int *)t24);
    t45 = (~(t44));
    t46 = *((unsigned int *)t23);
    t47 = (t46 & t45);
    t48 = (t47 != 0);
    if (t48 > 0)
        goto LAB57;

LAB58:
LAB59:    goto LAB28;

LAB31:    t49 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB32;

LAB33:    xsi_set_current_line(24, ng0);

LAB36:    xsi_set_current_line(25, ng0);
    t56 = ((char*)((ng5)));
    t57 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t57, t56, 0, 0, 1, 0LL);
    xsi_set_current_line(26, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_add(t4, 32, t5, 16, t6, 32);
    t8 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t8, t4, 0, 0, 16, 0LL);
    goto LAB35;

LAB39:    t22 = (t23 + 4);
    *((unsigned int *)t23) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB40;

LAB41:    xsi_set_current_line(29, ng0);

LAB44:    xsi_set_current_line(30, ng0);
    t25 = ((char*)((ng5)));
    t26 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t26, t25, 0, 0, 1, 0LL);
    xsi_set_current_line(31, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_add(t4, 32, t5, 16, t6, 32);
    t8 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t8, t4, 0, 0, 16, 0LL);
    goto LAB43;

LAB47:    t22 = (t23 + 4);
    *((unsigned int *)t23) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB48;

LAB49:    xsi_set_current_line(34, ng0);

LAB52:    xsi_set_current_line(35, ng0);
    t25 = ((char*)((ng5)));
    t26 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t26, t25, 0, 0, 1, 0LL);
    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_add(t4, 32, t5, 16, t6, 32);
    t8 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t8, t4, 0, 0, 16, 0LL);
    goto LAB51;

LAB55:    t22 = (t23 + 4);
    *((unsigned int *)t23) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB56;

LAB57:    xsi_set_current_line(39, ng0);

LAB60:    xsi_set_current_line(40, ng0);
    t25 = ((char*)((ng5)));
    t26 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t26, t25, 0, 0, 1, 0LL);
    xsi_set_current_line(41, ng0);
    t2 = (t0 + 1928);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t6 = ((char*)((ng5)));
    memset(t4, 0, 8);
    xsi_vlog_unsigned_add(t4, 32, t5, 16, t6, 32);
    t8 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t8, t4, 0, 0, 16, 0LL);
    goto LAB59;

LAB62:    *((unsigned int *)t4) = 1;
    goto LAB64;

LAB63:    t10 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB64;

LAB65:    xsi_set_current_line(49, ng0);
    t18 = ((char*)((ng1)));
    t21 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t21, t18, 0, 0, 16, 0LL);
    goto LAB67;

}


extern void work_m_00000000001225368792_3729631541_init()
{
	static char *pe[] = {(void *)Always_11_0};
	xsi_register_didat("work_m_00000000001225368792_3729631541", "isim/TestQ3_isim_beh.exe.sim/work/m_00000000001225368792_3729631541.didat");
	xsi_register_executes(pe);
}
