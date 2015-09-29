;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;&nbsp;Include&nbsp;文件定义
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
include		windows.inc
include		gdi32.inc
includelib	gdi32.lib
include		user32.inc
includelib	user32.lib
include		kernel32.inc
includelib	kernel32.lib
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;&nbsp;数据段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		.data?
hInstance	dd		?
hWinMain	dd		?
 
		.const
szClassName	db	&#39;MyClass&#39;,0
szCaptionMain	db	&#39;My&nbsp;first&nbsp;Window&nbsp;!&#39;,0
szText		db	&#39;Win32&nbsp;Assembly,&nbsp;Simple&nbsp;and&nbsp;powerful&nbsp;!&#39;,0
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;&nbsp;代码段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		.code
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;&nbsp;窗口过程
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_ProcWinMain	proc	uses&nbsp;ebx&nbsp;edi&nbsp;esi&nbsp;hWnd,uMsg,wParam,lParam
		local	@stPs:PAINTSTRUCT
		local	@stRect:RECT
		local	@hDc
 
		mov	eax,uMsg
;********************************************************************
		.if	eax&nbsp;==	WM_PAINT
			invoke	BeginPaint,hWnd,addr&nbsp;@stPs
			mov	@hDc,eax
 
			invoke	GetClientRect,hWnd,addr&nbsp;@stRect
			invoke	DrawText,@hDc,addr&nbsp;szText,-1,\
				addr&nbsp;@stRect,\
				DT_SINGLELINE&nbsp;or&nbsp;DT_CENTER&nbsp;or&nbsp;DT_VCENTER
 
			invoke	EndPaint,hWnd,addr&nbsp;@stPs
;********************************************************************
		.elseif	eax&nbsp;==	WM_CLOSE
			invoke	DestroyWindow,hWinMain
			invoke	PostQuitMessage,NULL
;********************************************************************
		.else
			invoke	DefWindowProc,hWnd,uMsg,wParam,lParam
			ret
		.endif
;********************************************************************
		xor	eax,eax
		ret
 
_ProcWinMain	endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_WinMain	proc
		local	@stWndClass:WNDCLASSEX
		local	@stMsg:MSG
 
		invoke	GetModuleHandle,NULL
		mov	hInstance,eax
		invoke	RtlZeroMemory,addr&nbsp;@stWndClass,sizeof&nbsp;@stWndClass
;********************************************************************
;&nbsp;注册窗口类
;********************************************************************
		invoke	LoadCursor,0,IDC_ARROW
		mov		@stWndClass.hCursor,eax
		push	hInstance
		pop		@stWndClass.hInstance
		mov		@stWndClass.cbSize,sizeof&nbsp;WNDCLASSEX
		mov		@stWndClass.style,CS_HREDRAW&nbsp;or&nbsp;CS_VREDRAW
		mov		@stWndClass.lpfnWndProc,offset&nbsp;_ProcWinMain
		mov		@stWndClass.hbrBackground,COLOR_WINDOW&nbsp;+&nbsp;1
		mov		@stWndClass.lpszClassName,offset&nbsp;szClassName
		invoke	RegisterClassEx,addr&nbsp;@stWndClass
;********************************************************************
;&nbsp;建立并显示窗口
;********************************************************************
		invoke	CreateWindowEx,WS_EX_CLIENTEDGE,offset&nbsp;szClassName,offset&nbsp;szCaptionMain,\
			WS_OVERLAPPEDWINDOW,\
			100,100,600,400,\
			NULL,NULL,hInstance,NULL
		mov	hWinMain,eax
		invoke	ShowWindow,hWinMain,SW_SHOWNORMAL
		invoke	UpdateWindow,hWinMain
;********************************************************************
;&nbsp;消息循环
;********************************************************************
		.while	TRUE
			invoke	GetMessage,addr&nbsp;@stMsg,NULL,0,0
			.break	.if&nbsp;eax	==&nbsp;0
			invoke	TranslateMessage,addr&nbsp;@stMsg
			invoke	DispatchMessage,addr&nbsp;@stMsg
		.endw
		ret
 
_WinMain	endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
start:
		call	_WinMain
		invoke	ExitProcess,NULL
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		end	start
