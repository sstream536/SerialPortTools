#pragma once

#define SERIALPORT_DLL_EXPORT __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif // 
	
SERIALPORT_DLL_EXPORT int commReadData(char* buffer,int size);
SERIALPORT_DLL_EXPORT int commWriteData(const char* buffer, int size);
SERIALPORT_DLL_EXPORT void setCommConfig(const char* com,int baudRate,char byteSize,char parity,char stopBits);
SERIALPORT_DLL_EXPORT void start();
SERIALPORT_DLL_EXPORT void end();

#ifdef __cplusplus
}
#endif // 