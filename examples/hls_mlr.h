#ifndef MLRC_DRIVERS_H_INCLUDED
#define MLRC_DRIVERS_H_INCLUDED

#include "mlrc_csr.h"

#define mlrc_write(offset, data)        			IOWR_32DIRECT  (MLRC_0_MLRC_INTERNAL_INST_AVS_CRA_BASE, offset, data)
#define mlrc_read(offset)               			IORD_32DIRECT  (MLRC_0_MLRC_INTERNAL_INST_AVS_CRA_BASE, offset)

#define mlrc_start()                   				mlrc_write     (MLRC_CSR_START_REG, MLRC_CSR_START_MASK & 0x1)
#define mlrc_busy()                     			mlrc_read      (MLRC_CSR_BUSY_REG) & MLRC_CSR_BUSY_MASK
#define mlrc_done()                     			mlrc_read      (MLRC_CSR_INTERRUPT_STATUS_REG) & MLRC_CSR_INTERRUPT_STATUS_MASK
///////////////////////////////////////////////

#define mlrc_disable_interrupt()        			mlrc_write     (MLRC_CSR_INTERRUPT_ENABLE_REG, MLRC_CSR_INTERRUPT_ENABLE_MASK & 0x0)
#define mlrc_clear_done_status()        			mlrc_write     (MLRC_CSR_INTERRUPT_STATUS_REG, MLRC_CSR_INTERRUPT_STATUS_MASK & 0x1)

#define mlrc_returndata()							mlrc_read	  (MLRC_CSR_RETURNDATA_REG) & MLRC_CSR_RETURNDATA_MASK

#endif

