import chisel3._
import chisel3.util._

class I2C_Top extends Module{
    val io = IO(new Bundle{
        val wdata = Input(UInt(32.W))
        val addr = Input(UInt(7.W))

        val sda = Output(Bool())
        val scl = Output(Bool())
    })

    //addresses
    val ADDR_Start_bit = 0.U
    val ADDR_SLAVE_ADDR = 4.U
    val ADDR_Read_Write_Bit = 8.U
    val ADDR_ACK = 12.U              //send by slave
    val ADDR_DATA = 16.U
    val ADDR_DATA_ACK = 20.U         //send by slave


    //registers
    val addr_start_bit = RegInit(0.B)
    val addr_slave_addr = RegInit(0.U(7.W))
    val addr_data = RegInit(0.U(8.W))
    val addr_read_write_bit = RegInit(0.B)
    val addr_ack = RegInit(0.B)                 //send by slave               
    val addr_data_ack = RegInit(0.B)                //send by slave


    //assign values
    when(io.addr === ADDR_Start_bit){
        addr_start_bit := io.wdata(0)
    }.elsewhen(io.addr === ADDR_SLAVE_ADDR){
        addr_slave_addr := io.wdata(6,0)
    }.elsewhen(io.addr === ADDR_DATA){
        addr_data := io.wdata(7,0)
    }.elsewhen(io.addr === ADDR_Read_Write_Bit){
        addr_read_write_bit := io.wdata(0)
    }.elsewhen(io.addr === ADDR_ACK){          //send by slave
         addr_ack := io.wdata(0)
    }.elsewhen(io.addr === ADDR_DATA_ACK){     //send by slave
         addr_data_ack := io.wdata(0)
    }.otherwise{
        addr_start_bit := 0.B
        addr_slave_addr := 0.U
        addr_data := 0.U
    }


    //Module Connections
    val i2c = Module(new i2c_master)
    i2c.io.start := addr_start_bit
    i2c.io.addr := addr_slave_addr
    i2c.io.data := addr_data
    i2c.io.read_write := addr_read_write_bit
    i2c.io.ack := addr_ack                       //send by slave
    i2c.io.data_ack := addr_data_ack             //send by slave

    io.sda := i2c.io.i2c_sda
    io.scl := i2c.io.i2c_scl



}