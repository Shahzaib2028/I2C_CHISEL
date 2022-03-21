// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2c_master__Syms.h"


//======================

void Vi2c_master::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vi2c_master::traceInit, &Vi2c_master::traceFull, &Vi2c_master::traceChg, this);
}
void Vi2c_master::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vi2c_master* t = (Vi2c_master*)userthis;
    Vi2c_master__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vi2c_master::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vi2c_master* t = (Vi2c_master*)userthis;
    Vi2c_master__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vi2c_master::traceInitThis(Vi2c_master__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vi2c_master::traceFullThis(Vi2c_master__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vi2c_master::traceInitThis__1(Vi2c_master__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+41,"clock", false,-1);
        vcdp->declBit(c+49,"reset", false,-1);
        vcdp->declBit(c+57,"io_start", false,-1);
        vcdp->declBus(c+65,"io_addr", false,-1, 6,0);
        vcdp->declBus(c+73,"io_data", false,-1, 7,0);
        vcdp->declBit(c+81,"io_read_write", false,-1);
        vcdp->declBit(c+89,"io_ack", false,-1);
        vcdp->declBit(c+97,"io_data_ack", false,-1);
        vcdp->declBit(c+105,"io_i2c_sda", false,-1);
        vcdp->declBit(c+113,"io_i2c_scl", false,-1);
        vcdp->declBit(c+121,"io_ready", false,-1);
        vcdp->declBit(c+129,"io_stop", false,-1);
        vcdp->declBit(c+41,"i2c_master clock", false,-1);
        vcdp->declBit(c+49,"i2c_master reset", false,-1);
        vcdp->declBit(c+57,"i2c_master io_start", false,-1);
        vcdp->declBus(c+65,"i2c_master io_addr", false,-1, 6,0);
        vcdp->declBus(c+73,"i2c_master io_data", false,-1, 7,0);
        vcdp->declBit(c+81,"i2c_master io_read_write", false,-1);
        vcdp->declBit(c+89,"i2c_master io_ack", false,-1);
        vcdp->declBit(c+97,"i2c_master io_data_ack", false,-1);
        vcdp->declBit(c+105,"i2c_master io_i2c_sda", false,-1);
        vcdp->declBit(c+113,"i2c_master io_i2c_scl", false,-1);
        vcdp->declBit(c+121,"i2c_master io_ready", false,-1);
        vcdp->declBit(c+129,"i2c_master io_stop", false,-1);
        vcdp->declBus(c+1,"i2c_master state", false,-1, 7,0);
        vcdp->declBus(c+9,"i2c_master count", false,-1, 14,0);
        vcdp->declBus(c+17,"i2c_master saved_addr", false,-1, 6,0);
        vcdp->declBus(c+25,"i2c_master saved_data", false,-1, 7,0);
        vcdp->declBit(c+33,"i2c_master i2c_scl_enable", false,-1);
    }
}

void Vi2c_master::traceFullThis__1(Vi2c_master__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c_master* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->i2c_master__DOT__state),8);
        vcdp->fullBus(c+9,(vlTOPp->i2c_master__DOT__count),15);
        vcdp->fullBus(c+17,(vlTOPp->i2c_master__DOT__saved_addr),7);
        vcdp->fullBus(c+25,(vlTOPp->i2c_master__DOT__saved_data),8);
        vcdp->fullBit(c+33,(vlTOPp->i2c_master__DOT__i2c_scl_enable));
        vcdp->fullBit(c+41,(vlTOPp->clock));
        vcdp->fullBit(c+49,(vlTOPp->reset));
        vcdp->fullBit(c+57,(vlTOPp->io_start));
        vcdp->fullBus(c+65,(vlTOPp->io_addr),7);
        vcdp->fullBus(c+73,(vlTOPp->io_data),8);
        vcdp->fullBit(c+81,(vlTOPp->io_read_write));
        vcdp->fullBit(c+89,(vlTOPp->io_ack));
        vcdp->fullBit(c+97,(vlTOPp->io_data_ack));
        vcdp->fullBit(c+105,(vlTOPp->io_i2c_sda));
        vcdp->fullBit(c+113,(vlTOPp->io_i2c_scl));
        vcdp->fullBit(c+121,(vlTOPp->io_ready));
        vcdp->fullBit(c+129,(vlTOPp->io_stop));
    }
}
