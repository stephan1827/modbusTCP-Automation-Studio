/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: MbusTCP
 * Author: strickers
 * Created: October 29, 2009
 *******************************************************************/
#include <MBdeclarations.h>

/* ------------------------------------------------------------------------------------------------- */
/* Swap or not swap, that is the question */
/* ------------------------------------------------------------------------------------------------- */
UINT MySwapUINT(UINT data)
{
	if(IsI386 || IsARM) return swapINT(data);
	return data;
}
INT MySwapINT(INT data)
{
	if(IsI386 || IsARM) return swapINT(data);
	return data;
}

/* ------------------------------------------------------------------------------------------------- */
/* Generate logbook message for requests and responses */
/* ------------------------------------------------------------------------------------------------- */
void MessageLog (USINT type, USINT function_code, UINT start_addr, UINT length, modbus_log_typ LOGBOOK)
{
	STRING str1[LOG_LINE_LEN];
	STRING str2[LOG_LINE_LEN];

	if(DEBUG_LEVEL ==1) return;
	
	if (type == TYP_REQUEST)
	{
		brsstrcpy((UDINT)str1, (UDINT)"Request FCT:");
		brsitoa(function_code, (UDINT)str2);
		brsstrcat((UDINT)str1, (UDINT)str2);
		brsstrcat((UDINT)str1, (UDINT)" ADR:");
		brsitoa(start_addr, (UDINT)str2);
		brsstrcat((UDINT)str1, (UDINT)str2);
		brsstrcat((UDINT)str1, (UDINT)" LEN:");
		brsitoa(length, (UDINT)str2);
		brsstrcat((UDINT)str1, (UDINT)str2);
	}
	else if (type == TYP_RESPONSE)
	{
		brsstrcpy((UDINT)str1, (UDINT)"Response FCT:");
		brsitoa(function_code, (UDINT)&str2);
		brsstrcat((UDINT)str1, (UDINT)str2);
		brsstrcat((UDINT)str1, (UDINT)" ok");
	}
	NewLogEntry(str1, LOGBOOK);	
}

/* ------------------------------------------------------------------------------------------------- */
/*	Generate logbook message */
/* ------------------------------------------------------------------------------------------------- */
void NewLogEntry (STRING message[LOG_LINE_LEN], modbus_log_typ LOGBOOK)
{
	RTCtime_typ	RTCtime_struct;
	STRING		lstr1[LOG_LINE_LEN], lstr2[LOG_LINE_LEN];
	
	/* Check if logging is enabled before writing to log */
	if ((LOGBOOK.data_lines > 0) && (LOGBOOK.pData != 0))
	{
		brsstrcpy((UDINT)lstr1, (UDINT)"");
		brsstrcpy((UDINT)lstr2, (UDINT)"");
		RTC_gettime(&RTCtime_struct);
		brsitoa(RTCtime_struct.hour, (UDINT)&lstr1);
		if(brsstrlen((UDINT)lstr1) == 1) brsstrcat((UDINT)lstr2, (UDINT)"0");
		brsstrcat((UDINT)lstr2, (UDINT)lstr1);
		brsstrcat((UDINT)lstr2, (UDINT)":");
		brsitoa(RTCtime_struct.minute, (UDINT)&lstr1);
		if(brsstrlen((UDINT)lstr1) == 1) brsstrcat((UDINT)lstr2, (UDINT)"0");
		brsstrcat((UDINT)lstr2, (UDINT)lstr1);
		brsstrcat((UDINT)lstr2, (UDINT)":");
		brsitoa(RTCtime_struct.second, (UDINT)&lstr1);
		if(brsstrlen((UDINT)lstr1) == 1) brsstrcat((UDINT)lstr2, (UDINT)"0");
		brsstrcat((UDINT)lstr2, (UDINT)lstr1);
		brsstrcat((UDINT)lstr2, (UDINT)":");
		brsitoa(RTCtime_struct.millisec, (UDINT)&lstr1);
		if(brsstrlen((UDINT)lstr1) == 1) brsstrcat((UDINT)lstr2, (UDINT)"00");
		if(brsstrlen((UDINT)lstr1) == 2) brsstrcat((UDINT)lstr2, (UDINT)"0");
		brsstrcat((UDINT)lstr2, (UDINT)lstr1);
		brsstrcat((UDINT)lstr2, (UDINT)" ");
		brsstrcat((UDINT)lstr2, (UDINT)message);
		brsmemmove((UDINT)(void*)(LOGBOOK.pData)+LOG_LINE_LEN+1, (UDINT)(void*)LOGBOOK.pData, (LOG_LINE_LEN+1)*(LOGBOOK.data_lines-1));
		brsstrcpy((UDINT)(void*)LOGBOOK.pData, (UDINT)lstr2);
	}
}
