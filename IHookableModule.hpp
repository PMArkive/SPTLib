#pragma once

#include "sptlib-stdafx.hpp"

class IHookableModule
{
public:
	virtual ~IHookableModule() {}
	virtual bool CanHook(const std::wstring& moduleFullName) = 0;
	virtual void* GetHandle();
	virtual std::wstring GetName();

	virtual void Hook(const std::wstring& moduleName, void* moduleHandle, void* moduleBase, size_t moduleLength) = 0;
	virtual void Unhook() = 0;
	virtual void Clear();

	virtual void TryHookAll() = 0;

protected:
	void *m_Handle;
	void *m_Base;
	size_t m_Length;
	std::wstring m_Name;
};