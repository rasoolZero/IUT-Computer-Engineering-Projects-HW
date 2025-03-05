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
static unsigned int ng1[] = {3U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {0U, 0U};



static void Always_50_0(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;

LAB0:    t1 = (t0 + 2664U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 2984);
    *((int *)t2) = 1;
    t3 = (t0 + 2696);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(50, ng0);

LAB5:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 1184U);
    t5 = *((char **)t4);
    t4 = (t0 + 1344U);
    t6 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t5 + 4);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t6);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t7) = 1;

LAB9:    t22 = (t7 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t7);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 1184U);
    t3 = *((char **)t2);
    t2 = (t0 + 1344U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t3 + 4);
    if (*((unsigned int *)t2) != 0)
        goto LAB14;

LAB13:    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB14;

LAB17:    if (*((unsigned int *)t3) > *((unsigned int *)t4))
        goto LAB15;

LAB16:    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 1184U);
    t3 = *((char **)t2);
    t2 = (t0 + 1344U);
    t4 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t3 + 4);
    if (*((unsigned int *)t2) != 0)
        goto LAB22;

LAB21:    t5 = (t4 + 4);
    if (*((unsigned int *)t5) != 0)
        goto LAB22;

LAB25:    if (*((unsigned int *)t3) < *((unsigned int *)t4))
        goto LAB23;

LAB24:    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB26;

LAB27:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 2);

LAB28:
LAB20:
LAB12:    goto LAB2;

LAB8:    t21 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(51, ng0);
    t28 = ((char*)((ng1)));
    t29 = (t0 + 1744);
    xsi_vlogvar_assign_value(t29, t28, 0, 0, 2);
    goto LAB12;

LAB14:    t6 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB16;

LAB15:    *((unsigned int *)t7) = 1;
    goto LAB16;

LAB18:    xsi_set_current_line(52, ng0);
    t21 = ((char*)((ng2)));
    t22 = (t0 + 1744);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 2);
    goto LAB20;

LAB22:    t6 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB24;

LAB23:    *((unsigned int *)t7) = 1;
    goto LAB24;

LAB26:    xsi_set_current_line(53, ng0);
    t21 = ((char*)((ng3)));
    t22 = (t0 + 1744);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 2);
    goto LAB28;

}


extern void work_m_00000000000389306428_1736564901_init()
{
	static char *pe[] = {(void *)Always_50_0};
	xsi_register_didat("work_m_00000000000389306428_1736564901", "isim/Q1_1_isim_beh.exe.sim/work/m_00000000000389306428_1736564901.didat");
	xsi_register_executes(pe);
}
