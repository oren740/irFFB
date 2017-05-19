/*
Copyright (c) 2016 NLP

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "resource.h"
#include "stdafx.h"
#include "irsdk_defines.h"

#define MAX_FFB_DEVICES 16
#define DI_MAX 10000
#define MINFORCE_MULTIPLIER 100
#define MIN_MAXFORCE 5
#define MAX_MAXFORCE 65
#define BUMPSFORCE_MULTIPLIER 1.6f
#define LOADFORCE_MULTIPLIER 0.08f
#define LONGLOAD_STDPOWER 4
#define LONGLOAD_MAXPOWER 8
#define STOPS_MAXFORCE_RAD 0.175f // 10 deg
#define DIRECT_INTERP_SAMPLES 6
#define KEY_PATH L"Software\\irFFB\\Settings"
#define INI_PATH L"\\irFFB.ini"
#define INI_SCAN_FORMAT  "%[^:]:%d:%d:%d:%d:%d:%d:%d\r"
#define INI_PRINT_FORMAT "%s:%d:%d:%d:%d:%d:%d:%d\r"
#define MAX_CAR_NAME 32

enum ffbType {
    FFBTYPE_360HZ,
    FFBTYPE_360HZ_INTERP,
    FFBTYPE_DIRECT_FILTER,
    FFBTYPE_UNKNOWN
};

DWORD WINAPI readWheelThread(LPVOID);
DWORD WINAPI directFFBThread(LPVOID);

ATOM MyRegisterClass(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

bool initVJD();
void text(wchar_t *, ...);
void text(wchar_t *, char *);
void setCarStatus(char *);
void setConnectedStatus(bool);
void setOnTrackStatus(bool);
void enumDirectInput();
void initDirectInput();
void reacquireDIDevice();
inline void sleepSpinUntil(PLARGE_INTEGER, UINT, UINT);
inline int scaleTorque(float);
inline void setFFB(int);
void initAll();
void releaseAll();

BOOL CALLBACK EnumFFDevicesCallback(LPCDIDEVICEINSTANCE, VOID *);
void CALLBACK vjFFBCallback(PVOID, PVOID);