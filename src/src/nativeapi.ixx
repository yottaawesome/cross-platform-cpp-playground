module;

#include <chrono>

export module nativeapi;

export namespace NativeAPI
{
	// This causes an ICE in GCC-13 when using chrono::milliseconds,
	// so I've converted it to an unsigned long until it gets fixed.
	void XPlatformSleep(std::chrono::milliseconds ms);
	void DoSomething() {}
	constexpr int DoEverything() { return 10; }
	constexpr int Whatever() { return 1; }
}