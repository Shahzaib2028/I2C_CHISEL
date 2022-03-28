import chisel3._
import chisel3 . util._
import org.scalatest._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation
import caravan.bus.wishbone.WishboneConfig
import caravan.bus.tilelink.TilelinkConfig
import caravan.bus.tilelink._

class i2cHarnessTest extends FreeSpec with ChiselScalatestTester {

  "I2C HARNESS TEST" in {
    implicit val config = WishboneConfig(32,32)
    test(new i2cHarness()) { c =>    

        c.io.request.bits.isWrite.poke(0.B)
        c.clock.step(1)

        c.io.request.bits.addrRequest.poke(4.U)
        c.clock.step(1)
        c.io.request.bits.dataRequest.poke(85.U)
        c.clock.step(1)
        c.io.request.bits.isWrite.poke(1.B)
        c.io.request.valid.poke(1.B)
        c.clock.step(1)
        // c.io.request.bits.isWrite.poke(0.B)
        c.io.request.valid.poke(0.B)
        c.clock.step(1)


        c.io.request.bits.addrRequest.poke(8.U)
        c.clock.step(1)
        c.io.request.bits.dataRequest.poke(0.U)
        c.clock.step(1)
        // c.io.request.bits.isWrite.poke(1.B)
        c.io.request.valid.poke(1.B)
        c.clock.step(1)
        // c.io.request.bits.isWrite.poke(0.B)
        c.io.request.valid.poke(0.B)
        c.clock.step(1)

        c.io.request.bits.addrRequest.poke(16.U)
        c.clock.step(1)
        c.io.request.bits.dataRequest.poke(145.U)
        c.clock.step(1)
        // c.io.request.bits.isWrite.poke(1.B)
        c.io.request.valid.poke(1.B)
        c.clock.step(1)
        // c.io.request.bits.isWrite.poke(0.B)
        c.io.request.valid.poke(0.B)
        c.clock.step(2)



        c.io.request.bits.addrRequest.poke(0.U)
        // c.clock.step(1)
        c.io.request.bits.dataRequest.poke(1.U)
        c.clock.step(1)
        c.io.request.bits.isWrite.poke(1.B)
        c.io.request.valid.poke(1.B)
        c.clock.step(1)
        // c.io.request.bits.isWrite.poke(0.B)
        c.io.request.valid.poke(0.B)
        c.clock.step(1)


        // c.io.request.bits.addrRequest.poke(4.U)
        // c.clock.step(1)
        // c.io.request.bits.dataRequest.poke(79.U)
        // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(1.B)
        // c.io.request.valid.poke(1.B)
        // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(0.B)
        // c.io.request.valid.poke(0.B)
        // c.clock.step(1)


        // c.io.request.bits.addrRequest.poke(8.U)
        // c.clock.step(1)
        // c.io.request.bits.dataRequest.poke(0.U)
        // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(1.B)
        // c.io.request.valid.poke(1.B)
        // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(0.B)
        // c.io.request.valid.poke(0.B)
        // c.clock.step(1)

        // c.io.request.bits.addrRequest.poke(12.U)
        // // c.clock.step(1)
        // c.io.request.bits.dataRequest.poke(0.U)
        // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(1.B)
        // c.io.request.valid.poke(1.B)
        // // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(0.B)
        // c.io.request.valid.poke(0.B)
        // // c.clock.step(1)

        // c.io.request.bits.addrRequest.poke(16.U)
        // c.clock.step(1)
        // c.io.request.bits.dataRequest.poke(125.U)
        // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(1.B)
        // c.io.request.valid.poke(1.B)
        // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(0.B)
        // c.io.request.valid.poke(0.B)
        // c.clock.step(1)

        // c.io.request.bits.addrRequest.poke(20.U)
        // // c.clock.step(1)
        // c.io.request.bits.dataRequest.poke(0.U)
        // // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(1.B)
        // c.io.request.valid.poke(1.B)
        // // c.clock.step(1)
        // // c.io.request.bits.isWrite.poke(0.B)
        // c.io.request.valid.poke(0.B)
        // c.clock.step(1)


       
        c.clock.step(100)


    }
  }
}