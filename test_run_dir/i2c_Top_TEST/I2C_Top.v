module i2c_master(
  input        clock,
  input        reset,
  input        io_start,
  input  [6:0] io_addr,
  input  [7:0] io_data,
  input        io_read_write,
  input        io_data_ack,
  output       io_i2c_sda,
  output       io_i2c_scl,
  output       io_i2c_intr
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] state; // @[i2c_master.scala 26:24]
  reg [14:0] count; // @[i2c_master.scala 27:24]
  reg  i2c_scl_enable; // @[i2c_master.scala 30:33]
  reg  intr_done; // @[i2c_master.scala 31:28]
  wire  _GEN_0 = state == 8'h0 | state == 8'h1 | state == 8'h6 ? 1'h0 : 1'h1; // @[i2c_master.scala 55:87 i2c_master.scala 56:28 i2c_master.scala 58:29]
  wire  _GEN_1 = reset ? 1'h0 : _GEN_0; // @[i2c_master.scala 52:22 i2c_master.scala 53:24]
  wire  _T_7 = 8'h0 == state; // @[Conditional.scala 37:30]
  wire [2:0] _GEN_2 = io_start ? 3'h1 : 3'h0; // @[i2c_master.scala 70:39 i2c_master.scala 71:27 i2c_master.scala 75:27]
  wire  _T_9 = 8'h1 == state; // @[Conditional.scala 37:30]
  wire  _T_10 = 8'h2 == state; // @[Conditional.scala 37:30]
  wire [6:0] _io_i2c_sda_T = io_addr >> count; // @[i2c_master.scala 91:38]
  wire  _T_11 = count == 15'h0; // @[i2c_master.scala 94:28]
  wire [14:0] _count_T_1 = count - 15'h1; // @[i2c_master.scala 97:36]
  wire [2:0] _GEN_4 = count == 15'h0 ? 3'h3 : 3'h2; // @[i2c_master.scala 94:36 i2c_master.scala 95:27 i2c_master.scala 98:27]
  wire [14:0] _GEN_5 = count == 15'h0 ? count : _count_T_1; // @[i2c_master.scala 94:36 i2c_master.scala 27:24 i2c_master.scala 97:27]
  wire  _T_12 = 8'h3 == state; // @[Conditional.scala 37:30]
  wire  _GEN_6 = ~io_read_write ? 1'h0 : 1'h1; // @[i2c_master.scala 104:44 i2c_master.scala 105:32 i2c_master.scala 111:32]
  wire [3:0] _GEN_9 = ~io_read_write ? 4'h8 : 4'h7; // @[i2c_master.scala 104:44 i2c_master.scala 109:27 i2c_master.scala 115:27]
  wire  _T_14 = 8'h4 == state; // @[Conditional.scala 37:30]
  wire [7:0] _io_i2c_sda_T_2 = io_data >> count; // @[i2c_master.scala 122:38]
  wire [2:0] _GEN_10 = _T_11 ? 3'h5 : 3'h4; // @[i2c_master.scala 125:36 i2c_master.scala 126:27 i2c_master.scala 129:27]
  wire  _T_16 = 8'h5 == state; // @[Conditional.scala 37:30]
  wire  _T_17 = 8'h6 == state; // @[Conditional.scala 37:30]
  wire  _GEN_13 = _T_17 | intr_done; // @[Conditional.scala 39:67 i2c_master.scala 143:27 i2c_master.scala 31:28]
  wire  _GEN_16 = _T_16 ? io_data_ack : 1'h1; // @[Conditional.scala 39:67 i2c_master.scala 135:28]
  wire [2:0] _GEN_18 = _T_16 ? 3'h6 : 3'h0; // @[Conditional.scala 39:67 i2c_master.scala 138:23]
  wire  _GEN_19 = _T_16 ? intr_done : _GEN_13; // @[Conditional.scala 39:67 i2c_master.scala 31:28]
  wire  _GEN_20 = _T_14 ? _io_i2c_sda_T_2[0] : _GEN_16; // @[Conditional.scala 39:67 i2c_master.scala 122:28]
  wire [2:0] _GEN_22 = _T_14 ? _GEN_10 : _GEN_18; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_23 = _T_14 ? _GEN_5 : count; // @[Conditional.scala 39:67 i2c_master.scala 27:24]
  wire  _GEN_24 = _T_14 ? intr_done : _GEN_19; // @[Conditional.scala 39:67 i2c_master.scala 31:28]
  wire  _GEN_25 = _T_12 ? _GEN_6 : _GEN_20; // @[Conditional.scala 39:67]
  wire [2:0] _GEN_27 = _T_12 ? 3'h4 : _GEN_22; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_28 = _T_12 ? {{11'd0}, _GEN_9} : _GEN_23; // @[Conditional.scala 39:67]
  wire  _GEN_29 = _T_12 ? intr_done : _GEN_24; // @[Conditional.scala 39:67 i2c_master.scala 31:28]
  wire  _GEN_30 = _T_10 ? _io_i2c_sda_T[0] : _GEN_25; // @[Conditional.scala 39:67 i2c_master.scala 91:28]
  wire [2:0] _GEN_32 = _T_10 ? _GEN_4 : _GEN_27; // @[Conditional.scala 39:67]
  wire [14:0] _GEN_33 = _T_10 ? _GEN_5 : _GEN_28; // @[Conditional.scala 39:67]
  wire  _GEN_34 = _T_10 ? intr_done : _GEN_29; // @[Conditional.scala 39:67 i2c_master.scala 31:28]
  wire  _GEN_35 = _T_9 ? 1'h0 : _GEN_30; // @[Conditional.scala 39:67 i2c_master.scala 81:28]
  wire [2:0] _GEN_40 = _T_9 ? 3'h2 : _GEN_32; // @[Conditional.scala 39:67 i2c_master.scala 86:23]
  wire  _GEN_43 = _T_7 | _GEN_35; // @[Conditional.scala 40:58 i2c_master.scala 68:28]
  wire [2:0] _GEN_45 = _T_7 ? _GEN_2 : _GEN_40; // @[Conditional.scala 40:58]
  wire [2:0] _GEN_51 = reset ? 3'h0 : _GEN_45; // @[i2c_master.scala 62:22 i2c_master.scala 63:15]
  assign io_i2c_sda = reset | _GEN_43; // @[i2c_master.scala 62:22 i2c_master.scala 64:20]
  assign io_i2c_scl = ~i2c_scl_enable | ~clock; // @[i2c_master.scala 50:22]
  assign io_i2c_intr = intr_done; // @[i2c_master.scala 151:17]
  always @(posedge clock) begin
    if (reset) begin // @[i2c_master.scala 26:24]
      state <= 8'h0; // @[i2c_master.scala 26:24]
    end else begin
      state <= {{5'd0}, _GEN_51};
    end
    if (reset) begin // @[i2c_master.scala 27:24]
      count <= 15'h0; // @[i2c_master.scala 27:24]
    end else if (!(reset)) begin // @[i2c_master.scala 62:22]
      if (!(_T_7)) begin // @[Conditional.scala 40:58]
        if (_T_9) begin // @[Conditional.scala 39:67]
          count <= 15'h6; // @[i2c_master.scala 87:23]
        end else begin
          count <= _GEN_33;
        end
      end
    end
    i2c_scl_enable <= reset | _GEN_1; // @[i2c_master.scala 30:33 i2c_master.scala 30:33]
    if (reset) begin // @[i2c_master.scala 31:28]
      intr_done <= 1'h0; // @[i2c_master.scala 31:28]
    end else if (!(reset)) begin // @[i2c_master.scala 62:22]
      if (_T_7) begin // @[Conditional.scala 40:58]
        intr_done <= 1'h0; // @[i2c_master.scala 69:27]
      end else if (!(_T_9)) begin // @[Conditional.scala 39:67]
        intr_done <= _GEN_34;
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
module I2C_Top(
  input         clock,
  input         reset,
  input  [31:0] io_wdata,
  input  [6:0]  io_addr,
  output        io_sda,
  output        io_scl,
  output        io_intr
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
`endif // RANDOMIZE_REG_INIT
  wire  i2c_clock; // @[I2C_Top.scala 53:21]
  wire  i2c_reset; // @[I2C_Top.scala 53:21]
  wire  i2c_io_start; // @[I2C_Top.scala 53:21]
  wire [6:0] i2c_io_addr; // @[I2C_Top.scala 53:21]
  wire [7:0] i2c_io_data; // @[I2C_Top.scala 53:21]
  wire  i2c_io_read_write; // @[I2C_Top.scala 53:21]
  wire  i2c_io_data_ack; // @[I2C_Top.scala 53:21]
  wire  i2c_io_i2c_sda; // @[I2C_Top.scala 53:21]
  wire  i2c_io_i2c_scl; // @[I2C_Top.scala 53:21]
  wire  i2c_io_i2c_intr; // @[I2C_Top.scala 53:21]
  reg  addr_start_bit; // @[I2C_Top.scala 24:33]
  reg [6:0] addr_slave_addr; // @[I2C_Top.scala 25:34]
  reg [7:0] addr_data; // @[I2C_Top.scala 26:28]
  reg  addr_read_write_bit; // @[I2C_Top.scala 27:38]
  reg  addr_data_ack; // @[I2C_Top.scala 29:32]
  wire  _GEN_0 = io_addr == 7'h14 ? io_wdata[0] : addr_data_ack; // @[I2C_Top.scala 43:42 I2C_Top.scala 44:24 I2C_Top.scala 29:32]
  wire  _GEN_1 = io_addr == 7'h14 & addr_start_bit; // @[I2C_Top.scala 43:42 I2C_Top.scala 24:33 I2C_Top.scala 46:24]
  wire [6:0] _GEN_2 = io_addr == 7'h14 ? addr_slave_addr : 7'h0; // @[I2C_Top.scala 43:42 I2C_Top.scala 25:34 I2C_Top.scala 47:25]
  wire [7:0] _GEN_3 = io_addr == 7'h14 ? addr_data : 8'h0; // @[I2C_Top.scala 43:42 I2C_Top.scala 26:28 I2C_Top.scala 48:19]
  wire  _GEN_5 = io_addr == 7'hc ? addr_data_ack : _GEN_0; // @[I2C_Top.scala 41:37 I2C_Top.scala 29:32]
  wire  _GEN_6 = io_addr == 7'hc ? addr_start_bit : _GEN_1; // @[I2C_Top.scala 41:37 I2C_Top.scala 24:33]
  wire [6:0] _GEN_7 = io_addr == 7'hc ? addr_slave_addr : _GEN_2; // @[I2C_Top.scala 41:37 I2C_Top.scala 25:34]
  wire [7:0] _GEN_8 = io_addr == 7'hc ? addr_data : _GEN_3; // @[I2C_Top.scala 41:37 I2C_Top.scala 26:28]
  wire  _GEN_9 = io_addr == 7'h8 ? io_wdata[0] : addr_read_write_bit; // @[I2C_Top.scala 39:48 I2C_Top.scala 40:29 I2C_Top.scala 27:38]
  wire  _GEN_11 = io_addr == 7'h8 ? addr_data_ack : _GEN_5; // @[I2C_Top.scala 39:48 I2C_Top.scala 29:32]
  wire  _GEN_12 = io_addr == 7'h8 ? addr_start_bit : _GEN_6; // @[I2C_Top.scala 39:48 I2C_Top.scala 24:33]
  wire [6:0] _GEN_13 = io_addr == 7'h8 ? addr_slave_addr : _GEN_7; // @[I2C_Top.scala 39:48 I2C_Top.scala 25:34]
  wire [7:0] _GEN_14 = io_addr == 7'h8 ? addr_data : _GEN_8; // @[I2C_Top.scala 39:48 I2C_Top.scala 26:28]
  i2c_master i2c ( // @[I2C_Top.scala 53:21]
    .clock(i2c_clock),
    .reset(i2c_reset),
    .io_start(i2c_io_start),
    .io_addr(i2c_io_addr),
    .io_data(i2c_io_data),
    .io_read_write(i2c_io_read_write),
    .io_data_ack(i2c_io_data_ack),
    .io_i2c_sda(i2c_io_i2c_sda),
    .io_i2c_scl(i2c_io_i2c_scl),
    .io_i2c_intr(i2c_io_i2c_intr)
  );
  assign io_sda = i2c_io_i2c_sda; // @[I2C_Top.scala 61:12]
  assign io_scl = i2c_io_i2c_scl; // @[I2C_Top.scala 62:12]
  assign io_intr = i2c_io_i2c_intr; // @[I2C_Top.scala 63:13]
  assign i2c_clock = clock;
  assign i2c_reset = reset;
  assign i2c_io_start = addr_start_bit; // @[I2C_Top.scala 54:18]
  assign i2c_io_addr = addr_slave_addr; // @[I2C_Top.scala 55:17]
  assign i2c_io_data = addr_data; // @[I2C_Top.scala 56:17]
  assign i2c_io_read_write = addr_read_write_bit; // @[I2C_Top.scala 57:23]
  assign i2c_io_data_ack = addr_data_ack; // @[I2C_Top.scala 59:21]
  always @(posedge clock) begin
    if (reset) begin // @[I2C_Top.scala 24:33]
      addr_start_bit <= 1'h0; // @[I2C_Top.scala 24:33]
    end else if (io_addr == 7'h0) begin // @[I2C_Top.scala 33:37]
      addr_start_bit <= io_wdata[0]; // @[I2C_Top.scala 34:24]
    end else if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 35:44]
      if (!(io_addr == 7'h10)) begin // @[I2C_Top.scala 37:38]
        addr_start_bit <= _GEN_12;
      end
    end
    if (reset) begin // @[I2C_Top.scala 25:34]
      addr_slave_addr <= 7'h0; // @[I2C_Top.scala 25:34]
    end else if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 33:37]
      if (io_addr == 7'h4) begin // @[I2C_Top.scala 35:44]
        addr_slave_addr <= io_wdata[6:0]; // @[I2C_Top.scala 36:25]
      end else if (!(io_addr == 7'h10)) begin // @[I2C_Top.scala 37:38]
        addr_slave_addr <= _GEN_13;
      end
    end
    if (reset) begin // @[I2C_Top.scala 26:28]
      addr_data <= 8'h0; // @[I2C_Top.scala 26:28]
    end else if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 33:37]
      if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 35:44]
        if (io_addr == 7'h10) begin // @[I2C_Top.scala 37:38]
          addr_data <= io_wdata[7:0]; // @[I2C_Top.scala 38:19]
        end else begin
          addr_data <= _GEN_14;
        end
      end
    end
    if (reset) begin // @[I2C_Top.scala 27:38]
      addr_read_write_bit <= 1'h0; // @[I2C_Top.scala 27:38]
    end else if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 33:37]
      if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 35:44]
        if (!(io_addr == 7'h10)) begin // @[I2C_Top.scala 37:38]
          addr_read_write_bit <= _GEN_9;
        end
      end
    end
    if (reset) begin // @[I2C_Top.scala 29:32]
      addr_data_ack <= 1'h0; // @[I2C_Top.scala 29:32]
    end else if (!(io_addr == 7'h0)) begin // @[I2C_Top.scala 33:37]
      if (!(io_addr == 7'h4)) begin // @[I2C_Top.scala 35:44]
        if (!(io_addr == 7'h10)) begin // @[I2C_Top.scala 37:38]
          addr_data_ack <= _GEN_11;
        end
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
  addr_start_bit = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  addr_slave_addr = _RAND_1[6:0];
  _RAND_2 = {1{`RANDOM}};
  addr_data = _RAND_2[7:0];
  _RAND_3 = {1{`RANDOM}};
  addr_read_write_bit = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  addr_data_ack = _RAND_4[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
