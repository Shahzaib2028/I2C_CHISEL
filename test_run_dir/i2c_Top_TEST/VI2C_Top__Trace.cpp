// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VI2C_Top__Syms.h"


//======================

void VI2C_Top::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VI2C_Top* t = (VI2C_Top*)userthis;
    VI2C_Top__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VI2C_Top::traceChgThis(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VI2C_Top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VI2C_Top::traceChgThis__2(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VI2C_Top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->I2C_Top__DOT__addr_start_bit));
        vcdp->chgBus(c+9,(vlTOPp->I2C_Top__DOT__addr_slave_addr),7);
        vcdp->chgBus(c+17,(vlTOPp->I2C_Top__DOT__addr_data),8);
        vcdp->chgBit(c+25,(vlTOPp->I2C_Top__DOT__addr_read_write_bit));
        vcdp->chgBit(c+33,(vlTOPp->I2C_Top__DOT__addr_sda_in));
        vcdp->chgBit(c+41,(vlTOPp->I2C_Top__DOT__i2c__DOT__intr_done));
        vcdp->chgBus(c+49,(vlTOPp->I2C_Top__DOT__i2c__DOT__state),8);
        vcdp->chgBus(c+57,(vlTOPp->I2C_Top__DOT__i2c__DOT__count),15);
        vcdp->chgBit(c+65,(vlTOPp->I2C_Top__DOT__i2c__DOT__i2c_scl_enable));
    }
}

void VI2C_Top::traceChgThis__3(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VI2C_Top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+73,(vlTOPp->clock));
        vcdp->chgBit(c+81,(vlTOPp->reset));
        vcdp->chgBus(c+89,(vlTOPp->io_wdata),32);
        vcdp->chgBus(c+97,(vlTOPp->io_addr),7);
        vcdp->chgBit(c+105,(vlTOPp->io_ren));
        vcdp->chgBit(c+113,(vlTOPp->io_we));
        vcdp->chgBit(c+121,(vlTOPp->io_sda_in));
        vcdp->chgBit(c+129,(vlTOPp->io_sda));
        vcdp->chgBit(c+137,(vlTOPp->io_scl));
        vcdp->chgBit(c+145,(vlTOPp->io_intr));
        vcdp->chgBit(c+153,(((IData)(vlTOPp->reset) 
                             | ((0U == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                | ((1U != (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                   & ((2U == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                       ? ((6U >= (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))
                                           ? (0x7fU 
                                              & ((IData)(vlTOPp->I2C_Top__DOT__addr_slave_addr) 
                                                 >> (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count)))
                                           : 0U) : 
                                      ((3U == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                        ? (IData)(vlTOPp->I2C_Top__DOT__addr_read_write_bit)
                                        : ((4U == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                            ? (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)
                                            : ((5U 
                                                == (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state))
                                                ? (
                                                   (7U 
                                                    >= (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))
                                                    ? 
                                                   (0xffU 
                                                    & ((IData)(vlTOPp->I2C_Top__DOT__addr_data) 
                                                       >> (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count)))
                                                    : 0U)
                                                : (
                                                   (6U 
                                                    != (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                                   | (IData)(vlTOPp->I2C_Top__DOT__addr_sda_in)))))))))));
        vcdp->chgBit(c+161,((1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__i2c_scl_enable)) 
                                   | (~ (IData)(vlTOPp->clock))))));
    }
}
