/*-----------------------------------------------------------------------*/
/* Low level disk I/O module SKELETON for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */
#include "sdcard.h"
#include "cli.h"

/* Definitions of physical drive number for each drive */
#define DEV_RAM		1	/* Example: Map Ramdisk to physical drive 0 */
#define DEV_MMC		0	/* Example: Map MMC/SD card to physical drive 1 */
#define DEV_USB		2	/* Example: Map USB MSD to physical drive 2 */


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
	DSTATUS stat=RES_OK;
	//int result;

	switch (pdrv) {
	case DEV_RAM :
		//result = RAM_disk_status();

		// translate the reslut code here

		return stat;

	case DEV_MMC :
		stat = sdcard_status();

		// translate the reslut code here

		return stat;

	case DEV_USB :
		//result = USB_disk_status();

		// translate the reslut code here

		return stat;
	}

	return RES_OK;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
	//DSTATUS stat;
	int result;

	switch (pdrv) {
	case DEV_RAM :
		//result = RAM_disk_initialize();

		// translate the reslut code here

		return RES_OK;

	case DEV_MMC :
		result = sdcard_init();

		// translate the reslut code here
		if(result)
			{
			if(result >0)
				return result;
			else
				return RES_NOTRDY;
			}
		else
			{
			return RES_OK;
			}

	case DEV_USB :
		//result = USB_disk_initialize();

		// translate the reslut code here

		return RES_OK;
	}
	return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	LBA_t sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
	DRESULT res=RES_OK;
	//int result;

	switch (pdrv) {
	case DEV_RAM :
		// translate the arguments here

		//result = RAM_disk_read(buff, sector, count);

		// translate the reslut code here
		//res = sdcard_read(buff, sector, count);

		return res;

	case DEV_MMC :
		// translate the arguments here

		res = sdcard_read(buff, sector, count);

		// translate the reslut code here

		return res;

	case DEV_USB :
		// translate the arguments here

		//result = USB_disk_read(buff, sector, count);

		// translate the reslut code here

		return res;
	}

	return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	LBA_t sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
	DRESULT res=RES_OK;
	int result;

	switch (pdrv) {
	case DEV_RAM :
		// translate the arguments here

		//result = RAM_disk_write(buff, sector, count);

		// translate the reslut code here
		//result = sdcard_write(buff, sector, count);
		//if(result == 0)
		//	res = RES_OK;

		return res;

	case DEV_MMC :
		// translate the arguments here

		result = sdcard_write(buff, sector, count);
		if(result == 0)
			res = RES_OK;

		// translate the reslut code here

		return res;

	case DEV_USB :
		// translate the arguments here

		//result = USB_disk_write(buff, sector, count);

		// translate the reslut code here

		return res;
	}

	return RES_PARERR;
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
	DRESULT res=RES_OK;
	//int result;

	switch (pdrv) {
	case DEV_RAM :

		// Process of the command for the RAM drive

		return res;

	case DEV_MMC :

		// Process of the command for the MMC/SD card
		if(CTRL_SYNC==cmd)
			{
			res = 0;
			}
		else if(GET_SECTOR_COUNT==cmd)
			{
			*(unsigned int*)buff = sdcard_get_sector_count();
			res = 0;
			}
		else if(GET_SECTOR_SIZE==cmd)
			{
			res = 0;
			}
		else if(GET_BLOCK_SIZE==cmd)
			{
			*(unsigned int*)buff = sdcard_get_blk_size();
			res = 0;
			}
		else if(CTRL_TRIM==cmd)
			{
			res = 0;
			}
		else
			{
			res = 0;
			}
		
		return res;

	case DEV_USB :

		// Process of the command the USB drive

		return res;
	}

	return RES_PARERR;
}

