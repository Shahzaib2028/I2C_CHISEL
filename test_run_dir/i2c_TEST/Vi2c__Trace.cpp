// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2c__Syms.h"


//======================

void Vi2c::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vi2c* t = (Vi2c*)userthis;
    Vi2c__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vi2c::traceChgThis(Vi2c__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vi2c::traceChgThis__2(Vi2c__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->i2c__DOT__state),8);
        vcdp->chgBus(c+9,(vlTOPp->i2c__DOT__count),15);
        vcdp->chgBus(c+17,(vlTOPp->i2c__DOT__saved_addr),7);
        vcdp->chgBus(c+25,(vlTOPp->i2c__DOT__saved_data),8);
        vcdp->chgBit(c+33,(vlTOPp->i2c__DOT__i2c_scl_enable));
    }
}

void Vi2c::traceChgThis__3(Vi2c__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vi2c* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+41,(vlTOPp->clock));
        vcdp->chgBit(c+49,(vlTOPp->reset));
        vcdp->chgBit(c+57,(vlTOPp->io_start));
        vcdp->chgBus(c+65,(vlTOPp->io_addr),7);
        vcdp->chgBus(c+73,(vlTOPp->io_data),8);
        vcdp->chgBit(c+81,(vlTOPp->io_read_write));
        vcdp->chgBit(c+89,(vlTOPp->io_ack));
        vcdp->chgBit(c+97,(vlTOPp->io_data_ack));
        vcdp->chgBit(c+105,(vlTOPp->io_i2c_sda));
        vcdp->chgBit(c+113,(vlTOPp->io_i2c_scl));
        vcdp->chgBit(c+121,(vlTOPp->io_ready));
        vcdp->chgBit(c+129,(vlTOPp->io_stop));
    }
}
