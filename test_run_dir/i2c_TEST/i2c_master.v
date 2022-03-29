module i2c_master(
  input        clock,
  input        reset,
  input        io_start,
  input  [6:0] io_addr,
  input  [7:0] io_data,
  input        io_read_write,
  input        io_i2c_sda_in,
  output       io_i2c_sda,
  output       io_i2c_scl,
  output       io_ready,
  output       io_stop,
  output       io_i2c_intr
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] state; // @[i2c_master.scala 25:24]
  reg [14:0] count; // @[i2c_master.scala 26:24]
  reg  i2c_scl_enable; // @[i2c_master.scala 29:33]
  reg  intr_done; // @[i2c_master.scala 30:28]
  wire  _GEN_0 = state == 8'h0 | state == 8'h1 | state == 8'h7 ? 1'h0 : 1'h1; // @[i2c_master.scala 54:87 i2c_master.scala 55:28 i2c_master.scala 57:29]
  wire  _GEN_1 = reset ? 1'h0 : _GEN_0; // @[i2c_master.scala 51:22 i2c_master.scala 52:24]
  wire  _T_7 = 8'h0 == state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_2 = io_start ? 3'h1 : 3'h0; // @[i2c_master.scala 69:39 i2c_master.scala 70:27 i2c_master.scala 74:27]
  wire  _T_9 = 8'h1 == state; // @[Conditional.scala 37:30]
  wire  _T_10 = 8'h2 == state; // @[Conditional.scala 37:30]
  wire [6:0] _io_i2c_sda_T = io_addr >> count; // @[i2c_master.scala 90:38]
  wire  _T_11 = count == 15'h0; // @[i2c_master.scala 93:28]
  wire [14:0] _count_T_1 = count - 15'h1; // @[i2c_master.scala 96:36]
  wire [2:0] _GEN_4 = count == 15'h0 ? 3'h3 : 3'h2; // @[i2c_master.scala 93:36 i2c_master.scala 94:27 i2c_master.scala 97:27]
  wire [14:0] _GEN_5 = count == 15'h0 ? count : _count_T_1; // @[i2c_master.scala 93:36 i2c_master.scala 26:24 i2c_master.scala 96:27]
  wire  _T_12 = 8'h3 == state; // @[Conditional.scala 37:30]
  wire  _GEN_6 = ~io_read_write ? 1'h0 : 1'h1; // @[i2c_master.scala 103:44 i2c_master.scala 104:32 i2c_master.scala 110:32]
  wire [3:0] _GEN_9 = ~io_read_write ? 4'h8 : 4'h7; // @[i2c_master.scala 103:44 i2c_master.scala 108:27 i2c_master.scala 114:27]
  wire  _T_14 = 8'h4 == state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_12 = ~io_i2c_sda_in ? 3'h5 : 3'h7; // @[i2c_master.scala 120:44 i2c_master.scala 124:23 i2c_master.scala 129:27]
  wire  _T_16 = 8'h5 == state; // @[Conditional.scala 37:30]
  wire [7:0] _io_i2c_sda_T_2 = io_data >> count; // @[i2c_master.scala 136:38]
  wire [2:0] _GEN_13 = _T_11 ? 3'h6 : 3'h5; // @[i2c_master.scala 139:36 i2c_master.scala 140:27 i2c_master.scala 143:27]
  wire  _T_18 = 8'h6 == state; // @[Conditional.scala 37:30]
  wire  _T_19 = 8'h7 == state; // @[Conditional.scala 37:30]
  wire  _GEN_16 = _T_19 | intr_done; // @[Conditional.scala 39:67 i2c_master.scala 157:27 i2c_master.scala 30:28]
  wire  _GEN_19 = _T_18 ? io_i2c_sda_in : 1'h1; // @[Conditional.scala 39:67 i2c_master.scala 149:28]
  wire [2:0] _GEN_21 = _T_18 ? 3'h7 : 3'h0; // @[Conditional.scala 39:67 i2c_master.scala 152:23]
  wire  _GEN_22 = _T_18 ? intr_done : _GEN_16; // @[Conditional.scala 39:67 i2c_master.scala 30:28]
  wire  _GEN_23 = _T_16 ? _io_i2c_sda_T_2[0] : _GEN_19; // @[Conditional.scala 39:67 i2c_master.scala 136:28]
  wire [2:0] _GEN_25 = _T_16 ? _GEN_13 : _GEN_21; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_26 = _T_16 ? _GEN_5 : count; // @[Conditional.scala 39:67 i2c_master.scala 26:24]
  wire  _GEN_27 = _T_16 ? intr_done : _GEN_22; // @[Conditional.scala 39:67 i2c_master.scala 30:28]
  wire  _GEN_28 = _T_14 ? io_i2c_sda_in : _GEN_23; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_30 = _T_14 ? _GEN_12 : _GEN_25; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_31 = _T_14 ? count : _GEN_26; // @[Conditional.scala 39:67 i2c_master.scala 26:24]
  wire  _GEN_32 = _T_14 ? intr_done : _GEN_27; // @[Conditional.scala 39:67 i2c_master.scala 30:28]
  wire  _GEN_33 = _T_12 ? _GEN_6 : _GEN_28; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_35 = _T_12 ? 3'h4 : _GEN_30; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_36 = _T_12 ? {{11'd0}, _GEN_9} : _GEN_31; // @[Conditional.scala 39:67]
  wire  _GEN_37 = _T_12 ? intr_done : _GEN_32; // @[Conditional.scala 39:67 i2c_master.scala 30:28]
  wire  _GEN_38 = _T_10 ? _io_i2c_sda_T[0] : _GEN_33; // @[Conditional.scala 39:67 i2c_master.scala 90:28]
  wire [2:0] _GEN_40 = _T_10 ? _GEN_4 : _GEN_35; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_41 = _T_10 ? _GEN_5 : _GEN_36; // @[Conditional.scala 39:67]
  wire  _GEN_42 = _T_10 ? intr_done : _GEN_37; // @[Conditional.scala 39:67 i2c_master.scala 30:28]
  wire  _GEN_43 = _T_9 ? 1'h0 : _GEN_38; // @[Conditional.scala 39:67 i2c_master.scala 80:28]
  wire [2:0] _GEN_48 = _T_9 ? 3'h2 : _GEN_40; // @[Conditional.scala 39:67 i2c_master.scala 85:23]
  wire  _GEN_51 = _T_7 | _GEN_43; // @[Conditional.scala 40:58 i2c_master.scala 67:28]
  wire [2:0] _GEN_53 = _T_7 ? _GEN_2 : _GEN_48; // @[Conditional.scala 40:58]
  wire  _GEN_54 = _T_7 ? 1'h0 : _T_9; // @[Conditional.scala 40:58]
  wire [2:0] _GEN_59 = reset ? 3'h0 : _GEN_53; // @[i2c_master.scala 61:22 i2c_master.scala 62:15]
  assign io_i2c_sda = reset | _GEN_51; // @[i2c_master.scala 61:22 i2c_master.scala 63:20]
  assign io_i2c_scl = ~i2c_scl_enable | ~clock; // @[i2c_master.scala 49:22]
  assign io_ready = reset ? 1'h0 : _GEN_54; // @[i2c_master.scala 61:22 i2c_master.scala 43:14]
  assign io_stop = 1'h0; // @[i2c_master.scala 61:22 i2c_master.scala 44:13]
  assign io_i2c_intr = intr_done; // @[i2c_master.scala 165:17]
  always @(posedge clock) begin
    if (reset) begin // @[i2c_master.scala 25:24]
      state <= 8'h0; // @[i2c_master.scala 25:24]
    end else begin
      state <= {{5'd0}, _GEN_59};
    end
    if (reset) begin // @[i2c_master.scala 26:24]
      count <= 15'h0; // @[i2c_master.scala 26:24]
    end else if (!(reset)) begin // @[i2c_master.scala 61:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          count <= 15'h6; // @[i2c_master.scala 86:23]
        end else begin
          count <= _GEN_41;
        end
      end
    end
    i2c_scl_enable <= reset | _GEN_1; // @[i2c_master.scala 29:33 i2c_master.scala 29:33]
    if (reset) begin // @[i2c_master.scala 30:28]
      intr_done <= 1'h0; // @[i2c_master.scala 30:28]
    end else if (!(reset)) begin // @[i2c_master.scala 61:22]
      if (_T_7) begin // @[Conditional.scala 40:58]
        intr_done <= 1'h0; // @[i2c_master.scala 68:27]
      end else if (!(_T_9)) begin // @[Conditional.scala 39:67]
        intr_done <= _GEN_42;
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  state = _RAND_0[7:0];
  _RAND_1 = {1{`RANDOM}};
  count = _RAND_1[14:0];
  _RAND_2 = {1{`RANDOM}};
  i2c_scl_enable = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  intr_done = _RAND_3[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
