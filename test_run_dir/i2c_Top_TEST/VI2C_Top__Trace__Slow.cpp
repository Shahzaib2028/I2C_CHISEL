// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VI2C_Top__Syms.h"


//======================

void VI2C_Top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VI2C_Top::traceInit, &VI2C_Top::traceFull, &VI2C_Top::traceChg, this);
}
void VI2C_Top::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VI2C_Top* t = (VI2C_Top*)userthis;
    VI2C_Top__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VI2C_Top::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VI2C_Top* t = (VI2C_Top*)userthis;
    VI2C_Top__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VI2C_Top::traceInitThis(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VI2C_Top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VI2C_Top::traceFullThis(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VI2C_Top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VI2C_Top::traceInitThis__1(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VI2C_Top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+73,"clock", false,-1);
        vcdp->declBit(c+81,"reset", false,-1);
        vcdp->declBus(c+89,"io_wdata", false,-1, 31,0);
        vcdp->declBus(c+97,"io_addr", false,-1, 6,0);
        vcdp->declBit(c+105,"io_sda", false,-1);
        vcdp->declBit(c+113,"io_scl", false,-1);
        vcdp->declBit(c+121,"io_intr", false,-1);
        vcdp->declBit(c+73,"I2C_Top clock", false,-1);
        vcdp->declBit(c+81,"I2C_Top reset", false,-1);
        vcdp->declBus(c+89,"I2C_Top io_wdata", false,-1, 31,0);
        vcdp->declBus(c+97,"I2C_Top io_addr", false,-1, 6,0);
        vcdp->declBit(c+105,"I2C_Top io_sda", false,-1);
        vcdp->declBit(c+113,"I2C_Top io_scl", false,-1);
        vcdp->declBit(c+121,"I2C_Top io_intr", false,-1);
        vcdp->declBit(c+73,"I2C_Top i2c_clock", false,-1);
        vcdp->declBit(c+81,"I2C_Top i2c_reset", false,-1);
        vcdp->declBit(c+1,"I2C_Top i2c_io_start", false,-1);
        vcdp->declBus(c+9,"I2C_Top i2c_io_addr", false,-1, 6,0);
        vcdp->declBus(c+17,"I2C_Top i2c_io_data", false,-1, 7,0);
        vcdp->declBit(c+25,"I2C_Top i2c_io_read_write", false,-1);
        vcdp->declBit(c+33,"I2C_Top i2c_io_data_ack", false,-1);
        vcdp->declBit(c+129,"I2C_Top i2c_io_i2c_sda", false,-1);
        vcdp->declBit(c+137,"I2C_Top i2c_io_i2c_scl", false,-1);
        vcdp->declBit(c+41,"I2C_Top i2c_io_i2c_intr", false,-1);
        vcdp->declBit(c+1,"I2C_Top addr_start_bit", false,-1);
        vcdp->declBus(c+9,"I2C_Top addr_slave_addr", false,-1, 6,0);
        vcdp->declBus(c+17,"I2C_Top addr_data", false,-1, 7,0);
        vcdp->declBit(c+25,"I2C_Top addr_read_write_bit", false,-1);
        vcdp->declBit(c+33,"I2C_Top addr_data_ack", false,-1);
        vcdp->declBit(c+73,"I2C_Top i2c clock", false,-1);
        vcdp->declBit(c+81,"I2C_Top i2c reset", false,-1);
        vcdp->declBit(c+1,"I2C_Top i2c io_start", false,-1);
        vcdp->declBus(c+9,"I2C_Top i2c io_addr", false,-1, 6,0);
        vcdp->declBus(c+17,"I2C_Top i2c io_data", false,-1, 7,0);
        vcdp->declBit(c+25,"I2C_Top i2c io_read_write", false,-1);
        vcdp->declBit(c+33,"I2C_Top i2c io_data_ack", false,-1);
        vcdp->declBit(c+129,"I2C_Top i2c io_i2c_sda", false,-1);
        vcdp->declBit(c+137,"I2C_Top i2c io_i2c_scl", false,-1);
        vcdp->declBit(c+41,"I2C_Top i2c io_i2c_intr", false,-1);
        vcdp->declBus(c+49,"I2C_Top i2c state", false,-1, 7,0);
        vcdp->declBus(c+57,"I2C_Top i2c count", false,-1, 14,0);
        vcdp->declBit(c+65,"I2C_Top i2c i2c_scl_enable", false,-1);
        vcdp->declBit(c+41,"I2C_Top i2c intr_done", false,-1);
    }
}

void VI2C_Top::traceFullThis__1(VI2C_Top__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VI2C_Top* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->I2C_Top__DOT__addr_start_bit));
        vcdp->fullBus(c+9,(vlTOPp->I2C_Top__DOT__addr_slave_addr),7);
        vcdp->fullBus(c+17,(vlTOPp->I2C_Top__DOT__addr_data),8);
        vcdp->fullBit(c+25,(vlTOPp->I2C_Top__DOT__addr_read_write_bit));
        vcdp->fullBit(c+33,(vlTOPp->I2C_Top__DOT__addr_data_ack));
        vcdp->fullBit(c+41,(vlTOPp->I2C_Top__DOT__i2c__DOT__intr_done));
        vcdp->fullBus(c+49,(vlTOPp->I2C_Top__DOT__i2c__DOT__state),8);
        vcdp->fullBus(c+57,(vlTOPp->I2C_Top__DOT__i2c__DOT__count),15);
        vcdp->fullBit(c+65,(vlTOPp->I2C_Top__DOT__i2c__DOT__i2c_scl_enable));
        vcdp->fullBit(c+73,(vlTOPp->clock));
        vcdp->fullBit(c+81,(vlTOPp->reset));
        vcdp->fullBus(c+89,(vlTOPp->io_wdata),32);
        vcdp->fullBus(c+97,(vlTOPp->io_addr),7);
        vcdp->fullBit(c+105,(vlTOPp->io_sda));
        vcdp->fullBit(c+113,(vlTOPp->io_scl));
        vcdp->fullBit(c+121,(vlTOPp->io_intr));
        vcdp->fullBit(c+129,(((IData)(vlTOPp->reset) 
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
                                             ? ((7U 
                                                 >= (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count))
                                                 ? 
                                                (0xffU 
                                                 & ((IData)(vlTOPp->I2C_Top__DOT__addr_data) 
                                                    >> (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__count)))
                                                 : 0U)
                                             : ((5U 
                                                 != (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__state)) 
                                                | (IData)(vlTOPp->I2C_Top__DOT__addr_data_ack))))))))));
        vcdp->fullBit(c+137,((1U & ((~ (IData)(vlTOPp->I2C_Top__DOT__i2c__DOT__i2c_scl_enable)) 
                                    | (~ (IData)(vlTOPp->clock))))));
    }
}
