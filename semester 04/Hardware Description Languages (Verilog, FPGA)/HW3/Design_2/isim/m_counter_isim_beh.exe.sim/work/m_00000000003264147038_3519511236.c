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
static const char *ng0 = "E:/rasool/IUT/t4/FPGA/HWs/HW2/Project/Q2.v";
static int ng1[] = {1000, 0};
static int ng2[] = {2000, 0};
static int ng3[] = {5000, 0};
static int ng4[] = {0, 0};
static int ng5[] = {1, 0};



static void Cont_13_0(char *t0)
{
    char t6[8];
    char t11[8];
    char t12[8];
    char t17[8];
    char t18[8];
    char t21[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t19;
    char *t20;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;

LAB0:    t1 = (t0 + 4128U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(13, ng0);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_multiply(t6, 32, t4, 9, t5, 32);
    t7 = (t0 + 2568);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = ((char*)((ng2)));
    memset(t11, 0, 8);
    xsi_vlog_unsigned_multiply(t11, 32, t9, 8, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_add(t12, 32, t6, 32, t11, 32);
    t13 = (t0 + 2728);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng3)));
    memset(t17, 0, 8);
    xsi_vlog_unsigned_multiply(t17, 32, t15, 7, t16, 32);
    memset(t18, 0, 8);
    xsi_vlog_unsigned_add(t18, 32, t12, 32, t17, 32);
    t19 = (t0 + 2008U);
    t20 = *((char **)t19);
    memset(t21, 0, 8);
    t19 = (t18 + 4);
    if (*((unsigned int *)t19) != 0)
        goto LAB5;

LAB4:    t22 = (t20 + 4);
    if (*((unsigned int *)t22) != 0)
        goto LAB5;

LAB8:    if (*((unsigned int *)t18) < *((unsigned int *)t20))
        goto LAB7;

LAB6:    *((unsigned int *)t21) = 1;

LAB7:    t24 = (t0 + 4792);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memset(t28, 0, 8);
    t29 = 1U;
    t30 = t29;
    t31 = (t21 + 4);
    t32 = *((unsigned int *)t21);
    t29 = (t29 & t32);
    t33 = *((unsigned int *)t31);
    t30 = (t30 & t33);
    t34 = (t28 + 4);
    t35 = *((unsigned int *)t28);
    *((unsigned int *)t28) = (t35 | t29);
    t36 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t36 | t30);
    xsi_driver_vfirst_trans(t24, 0, 0);
    t37 = (t0 + 4696);
    *((int *)t37) = 1;

LAB1:    return;
LAB5:    t23 = (t21 + 4);
    *((unsigned int *)t21) = 1;
    *((unsigned int *)t23) = 1;
    goto LAB7;

}

static void Always_16_1(char *t0)
{
    char t6[8];
    char t30[8];
    char t36[8];
    char t52[8];
    char t60[8];
    char t103[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
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
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t37;
    char *t38;
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
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    int t84;
    int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    char *t99;
    char *t100;
    char *t101;
    char *t102;

LAB0:    t1 = (t0 + 4376U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(16, ng0);
    t2 = (t0 + 4712);
    *((int *)t2) = 1;
    t3 = (t0 + 4408);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(16, ng0);

LAB5:    xsi_set_current_line(17, ng0);
    t4 = (t0 + 1368U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(25, ng0);

LAB14:    xsi_set_current_line(26, ng0);
    t2 = (t0 + 1528U);
    t3 = *((char **)t2);
    t2 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(27, ng0);
    t2 = (t0 + 1688U);
    t3 = *((char **)t2);
    t2 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(28, ng0);
    t2 = (t0 + 1848U);
    t3 = *((char **)t2);
    t2 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 1, 0LL);
    xsi_set_current_line(29, ng0);
    t2 = (t0 + 2888);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB18;

LAB15:    if (t18 != 0)
        goto LAB17;

LAB16:    *((unsigned int *)t6) = 1;

LAB18:    memset(t30, 0, 8);
    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t22) != 0)
        goto LAB21;

LAB22:    t29 = (t30 + 4);
    t31 = *((unsigned int *)t30);
    t32 = *((unsigned int *)t29);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB23;

LAB24:    memcpy(t60, t30, 8);

LAB25:    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB37;

LAB38:
LAB39:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 3048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB43;

LAB40:    if (t18 != 0)
        goto LAB42;

LAB41:    *((unsigned int *)t6) = 1;

LAB43:    memset(t30, 0, 8);
    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB44;

LAB45:    if (*((unsigned int *)t22) != 0)
        goto LAB46;

LAB47:    t29 = (t30 + 4);
    t31 = *((unsigned int *)t30);
    t32 = *((unsigned int *)t29);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB48;

LAB49:    memcpy(t60, t30, 8);

LAB50:    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB62;

LAB63:
LAB64:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 3208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB68;

LAB65:    if (t18 != 0)
        goto LAB67;

LAB66:    *((unsigned int *)t6) = 1;

LAB68:    memset(t30, 0, 8);
    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB69;

LAB70:    if (*((unsigned int *)t22) != 0)
        goto LAB71;

LAB72:    t29 = (t30 + 4);
    t31 = *((unsigned int *)t30);
    t32 = *((unsigned int *)t29);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB73;

LAB74:    memcpy(t60, t30, 8);

LAB75:    t92 = (t60 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (~(t93));
    t95 = *((unsigned int *)t60);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB87;

LAB88:
LAB89:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(17, ng0);

LAB13:    xsi_set_current_line(18, ng0);
    t28 = ((char*)((ng4)));
    t29 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t29, t28, 0, 0, 9, 0LL);
    xsi_set_current_line(19, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 8, 0LL);
    xsi_set_current_line(20, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 7, 0LL);
    xsi_set_current_line(21, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(22, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    xsi_set_current_line(23, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);
    goto LAB12;

LAB17:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB18;

LAB19:    *((unsigned int *)t30) = 1;
    goto LAB22;

LAB21:    t28 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB22;

LAB23:    t34 = (t0 + 1528U);
    t35 = *((char **)t34);
    t34 = ((char*)((ng5)));
    memset(t36, 0, 8);
    t37 = (t35 + 4);
    t38 = (t34 + 4);
    t39 = *((unsigned int *)t35);
    t40 = *((unsigned int *)t34);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t37);
    t43 = *((unsigned int *)t38);
    t44 = (t42 ^ t43);
    t45 = (t41 | t44);
    t46 = *((unsigned int *)t37);
    t47 = *((unsigned int *)t38);
    t48 = (t46 | t47);
    t49 = (~(t48));
    t50 = (t45 & t49);
    if (t50 != 0)
        goto LAB29;

LAB26:    if (t48 != 0)
        goto LAB28;

LAB27:    *((unsigned int *)t36) = 1;

LAB29:    memset(t52, 0, 8);
    t53 = (t36 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t36);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB30;

LAB31:    if (*((unsigned int *)t53) != 0)
        goto LAB32;

LAB33:    t61 = *((unsigned int *)t30);
    t62 = *((unsigned int *)t52);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t30 + 4);
    t65 = (t52 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB34;

LAB35:
LAB36:    goto LAB25;

LAB28:    t51 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB29;

LAB30:    *((unsigned int *)t52) = 1;
    goto LAB33;

LAB32:    t59 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB33;

LAB34:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t30 + 4);
    t75 = (t52 + 4);
    t76 = *((unsigned int *)t30);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t52);
    t81 = (~(t80));
    t82 = *((unsigned int *)t75);
    t83 = (~(t82));
    t84 = (t77 & t79);
    t85 = (t81 & t83);
    t86 = (~(t84));
    t87 = (~(t85));
    t88 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t88 & t86);
    t89 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t89 & t87);
    t90 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t90 & t86);
    t91 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t91 & t87);
    goto LAB36;

LAB37:    xsi_set_current_line(30, ng0);
    t98 = (t0 + 2408);
    t99 = (t98 + 56U);
    t100 = *((char **)t99);
    t101 = (t0 + 1528U);
    t102 = *((char **)t101);
    memset(t103, 0, 8);
    xsi_vlog_unsigned_add(t103, 9, t100, 9, t102, 1);
    t101 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t101, t103, 0, 0, 9, 0LL);
    goto LAB39;

LAB42:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB43;

LAB44:    *((unsigned int *)t30) = 1;
    goto LAB47;

LAB46:    t28 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB47;

LAB48:    t34 = (t0 + 1688U);
    t35 = *((char **)t34);
    t34 = ((char*)((ng5)));
    memset(t36, 0, 8);
    t37 = (t35 + 4);
    t38 = (t34 + 4);
    t39 = *((unsigned int *)t35);
    t40 = *((unsigned int *)t34);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t37);
    t43 = *((unsigned int *)t38);
    t44 = (t42 ^ t43);
    t45 = (t41 | t44);
    t46 = *((unsigned int *)t37);
    t47 = *((unsigned int *)t38);
    t48 = (t46 | t47);
    t49 = (~(t48));
    t50 = (t45 & t49);
    if (t50 != 0)
        goto LAB54;

LAB51:    if (t48 != 0)
        goto LAB53;

LAB52:    *((unsigned int *)t36) = 1;

LAB54:    memset(t52, 0, 8);
    t53 = (t36 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t36);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB55;

LAB56:    if (*((unsigned int *)t53) != 0)
        goto LAB57;

LAB58:    t61 = *((unsigned int *)t30);
    t62 = *((unsigned int *)t52);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t30 + 4);
    t65 = (t52 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB59;

LAB60:
LAB61:    goto LAB50;

LAB53:    t51 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB54;

LAB55:    *((unsigned int *)t52) = 1;
    goto LAB58;

LAB57:    t59 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB58;

LAB59:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t30 + 4);
    t75 = (t52 + 4);
    t76 = *((unsigned int *)t30);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t52);
    t81 = (~(t80));
    t82 = *((unsigned int *)t75);
    t83 = (~(t82));
    t84 = (t77 & t79);
    t85 = (t81 & t83);
    t86 = (~(t84));
    t87 = (~(t85));
    t88 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t88 & t86);
    t89 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t89 & t87);
    t90 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t90 & t86);
    t91 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t91 & t87);
    goto LAB61;

LAB62:    xsi_set_current_line(32, ng0);
    t98 = (t0 + 2568);
    t99 = (t98 + 56U);
    t100 = *((char **)t99);
    t101 = (t0 + 1688U);
    t102 = *((char **)t101);
    memset(t103, 0, 8);
    xsi_vlog_unsigned_add(t103, 8, t100, 8, t102, 1);
    t101 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t101, t103, 0, 0, 8, 0LL);
    goto LAB64;

LAB67:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB68;

LAB69:    *((unsigned int *)t30) = 1;
    goto LAB72;

LAB71:    t28 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB72;

LAB73:    t34 = (t0 + 1848U);
    t35 = *((char **)t34);
    t34 = ((char*)((ng5)));
    memset(t36, 0, 8);
    t37 = (t35 + 4);
    t38 = (t34 + 4);
    t39 = *((unsigned int *)t35);
    t40 = *((unsigned int *)t34);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t37);
    t43 = *((unsigned int *)t38);
    t44 = (t42 ^ t43);
    t45 = (t41 | t44);
    t46 = *((unsigned int *)t37);
    t47 = *((unsigned int *)t38);
    t48 = (t46 | t47);
    t49 = (~(t48));
    t50 = (t45 & t49);
    if (t50 != 0)
        goto LAB79;

LAB76:    if (t48 != 0)
        goto LAB78;

LAB77:    *((unsigned int *)t36) = 1;

LAB79:    memset(t52, 0, 8);
    t53 = (t36 + 4);
    t54 = *((unsigned int *)t53);
    t55 = (~(t54));
    t56 = *((unsigned int *)t36);
    t57 = (t56 & t55);
    t58 = (t57 & 1U);
    if (t58 != 0)
        goto LAB80;

LAB81:    if (*((unsigned int *)t53) != 0)
        goto LAB82;

LAB83:    t61 = *((unsigned int *)t30);
    t62 = *((unsigned int *)t52);
    t63 = (t61 & t62);
    *((unsigned int *)t60) = t63;
    t64 = (t30 + 4);
    t65 = (t52 + 4);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t64);
    t68 = *((unsigned int *)t65);
    t69 = (t67 | t68);
    *((unsigned int *)t66) = t69;
    t70 = *((unsigned int *)t66);
    t71 = (t70 != 0);
    if (t71 == 1)
        goto LAB84;

LAB85:
LAB86:    goto LAB75;

LAB78:    t51 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB79;

LAB80:    *((unsigned int *)t52) = 1;
    goto LAB83;

LAB82:    t59 = (t52 + 4);
    *((unsigned int *)t52) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB83;

LAB84:    t72 = *((unsigned int *)t60);
    t73 = *((unsigned int *)t66);
    *((unsigned int *)t60) = (t72 | t73);
    t74 = (t30 + 4);
    t75 = (t52 + 4);
    t76 = *((unsigned int *)t30);
    t77 = (~(t76));
    t78 = *((unsigned int *)t74);
    t79 = (~(t78));
    t80 = *((unsigned int *)t52);
    t81 = (~(t80));
    t82 = *((unsigned int *)t75);
    t83 = (~(t82));
    t84 = (t77 & t79);
    t85 = (t81 & t83);
    t86 = (~(t84));
    t87 = (~(t85));
    t88 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t88 & t86);
    t89 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t89 & t87);
    t90 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t90 & t86);
    t91 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t91 & t87);
    goto LAB86;

LAB87:    xsi_set_current_line(34, ng0);
    t98 = (t0 + 2728);
    t99 = (t98 + 56U);
    t100 = *((char **)t99);
    t101 = (t0 + 1848U);
    t102 = *((char **)t101);
    memset(t103, 0, 8);
    xsi_vlog_unsigned_add(t103, 7, t100, 7, t102, 1);
    t101 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t101, t103, 0, 0, 7, 0LL);
    goto LAB89;

}


extern void work_m_00000000003264147038_3519511236_init()
{
	static char *pe[] = {(void *)Cont_13_0,(void *)Always_16_1};
	xsi_register_didat("work_m_00000000003264147038_3519511236", "isim/m_counter_isim_beh.exe.sim/work/m_00000000003264147038_3519511236.didat");
	xsi_register_executes(pe);
}
