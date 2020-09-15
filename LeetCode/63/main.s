	.file	"main.cpp"
	.intel_syntax noprefix
	.text
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB2691:
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	cmp	ecx, 1
	je	.L3
.L1:
	add	rsp, 40
	ret
.L3:
	cmp	edx, 65535
	jne	.L1
	lea	rcx, _ZStL8__ioinit[rip]
	call	_ZNSt8ios_base4InitC1Ev
	lea	rcx, __tcf_0[rip]
	call	atexit
	jmp	.L1
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2692:
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	lea	rcx, _ZStL8__ioinit[rip]
	call	_ZNSt8ios_base4InitD1Ev
	nop
	add	rsp, 40
	ret
	.seh_endproc
	.section	.text$_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	.def	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev:
.LFB2212:
	push	rdi
	.seh_pushreg	rdi
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 32
	.seh_stackalloc	32
	.seh_endprologue
	mov	rdi, rcx
	mov	rsi, QWORD PTR 8[rcx]
	mov	rbx, QWORD PTR [rcx]
	jmp	.L8
.L7:
	add	rbx, 24
.L8:
	cmp	rsi, rbx
	je	.L6
	mov	rcx, QWORD PTR [rbx]
	test	rcx, rcx
	je	.L7
	call	_ZdlPv
	jmp	.L7
.L6:
	mov	rcx, QWORD PTR [rdi]
	test	rcx, rcx
	je	.L5
	call	_ZdlPv
	nop
.L5:
	add	rsp, 32
	pop	rbx
	pop	rsi
	pop	rdi
	ret
	.seh_endproc
	.section	.text$_ZSt12__niter_baseIPKlSt6vectorIlSaIlEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE,"x"
	.linkonce discard
	.globl	_ZSt12__niter_baseIPKlSt6vectorIlSaIlEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	.def	_ZSt12__niter_baseIPKlSt6vectorIlSaIlEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt12__niter_baseIPKlSt6vectorIlSaIlEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
_ZSt12__niter_baseIPKlSt6vectorIlSaIlEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE:
.LFB2685:
	.seh_endprologue
	mov	rax, rcx
	ret
	.seh_endproc
	.section	.text$_ZN8Solution24uniquePathsWithObstaclesERSt6vectorIS0_IiSaIiEESaIS2_EE,"x"
	.linkonce discard
	.align 2
	.globl	_ZN8Solution24uniquePathsWithObstaclesERSt6vectorIS0_IiSaIiEESaIS2_EE
	.def	_ZN8Solution24uniquePathsWithObstaclesERSt6vectorIS0_IiSaIiEESaIS2_EE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8Solution24uniquePathsWithObstaclesERSt6vectorIS0_IiSaIiEESaIS2_EE
_ZN8Solution24uniquePathsWithObstaclesERSt6vectorIS0_IiSaIiEESaIS2_EE:
.LFB1915:
	push	r15
	.seh_pushreg	r15
	push	r14
	.seh_pushreg	r14
	push	r13
	.seh_pushreg	r13
	push	r12
	.seh_pushreg	r12
	push	rbp
	.seh_pushreg	rbp
	push	rdi
	.seh_pushreg	rdi
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 136
	.seh_stackalloc	136
	.seh_endprologue
	mov	rbx, rdx
	mov	rdx, QWORD PTR [rdx]
	mov	rax, QWORD PTR 8[rbx]
	sub	rax, rdx
	sar	rax, 3
	movabs	rcx, -6148914691236517205
	imul	rax, rcx
	mov	QWORD PTR 40[rsp], rax
	mov	r13d, eax
	mov	rax, QWORD PTR 8[rdx]
	sub	rax, QWORD PTR [rdx]
	sar	rax, 2
	mov	QWORD PTR 56[rsp], rax
	mov	esi, eax
	movsx	rdi, eax
	test	rdi, rdi
	je	.L48
	movabs	rax, 4611686018427387903
	cmp	rdi, rax
	ja	.L60
	lea	rcx, 0[0+rdi*4]
.LEHB0:
	call	_Znwy
.L12:
	mov	QWORD PTR 96[rsp], rax
.L15:
	test	rdi, rdi
	je	.L14
	mov	DWORD PTR [rax], 0
	sub	rdi, 1
	add	rax, 4
	jmp	.L15
.L60:
	call	_ZSt17__throw_bad_allocv
.LEHE0:
.L48:
	mov	eax, 0
	jmp	.L12
.L14:
	mov	QWORD PTR 104[rsp], rax
	movsx	r12, DWORD PTR 40[rsp]
	test	r12, r12
	je	.L49
	movabs	rax, 768614336404564650
	cmp	r12, rax
	ja	.L61
	lea	rax, [r12+r12*2]
	lea	rcx, 0[0+rax*8]
.LEHB1:
	call	_Znwy
	jmp	.L62
.L61:
	call	_ZSt17__throw_bad_allocv
.LEHE1:
.L57:
	mov	rbx, rax
	jmp	.L32
.L62:
	mov	QWORD PTR 48[rsp], rax
.L16:
	mov	rax, QWORD PTR 48[rsp]
	mov	QWORD PTR 64[rsp], rax
	mov	rdi, rax
	jmp	.L23
.L49:
	mov	QWORD PTR 48[rsp], 0
	jmp	.L16
.L63:
.LEHB2:
	call	_ZSt17__throw_bad_allocv
.L59:
	mov	rcx, rax
	call	__cxa_begin_catch
.L29:
	mov	rax, QWORD PTR 48[rsp]
	cmp	rdi, rax
	je	.L27
	mov	rcx, QWORD PTR [rax]
	test	rcx, rcx
	je	.L28
	call	_ZdlPv
.L28:
	add	QWORD PTR 48[rsp], 24
	jmp	.L29
.L64:
	mov	rbp, rax
.L20:
	mov	QWORD PTR [rdi], rbp
	mov	QWORD PTR 8[rdi], rbp
	add	r14, rbp
	mov	QWORD PTR 16[rdi], r14
	mov	rcx, QWORD PTR 104[rsp]
	call	_ZSt12__niter_baseIPKlSt6vectorIlSaIlEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	mov	r14, rax
	mov	rcx, QWORD PTR 96[rsp]
	call	_ZSt12__niter_baseIPKlSt6vectorIlSaIlEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	mov	r15, r14
	sub	r15, rax
	cmp	r14, rax
	je	.L22
	mov	r8, r15
	mov	rdx, rax
	mov	rcx, rbp
	call	memmove
.L22:
	add	rbp, r15
	mov	QWORD PTR 8[rdi], rbp
.L19:
	sub	r12, 1
	add	rdi, 24
.L23:
	test	r12, r12
	je	.L18
	test	rdi, rdi
	je	.L19
	mov	r14, QWORD PTR 104[rsp]
	sub	r14, QWORD PTR 96[rsp]
	mov	rcx, r14
	sar	rcx, 2
	mov	QWORD PTR [rdi], 0
	mov	QWORD PTR 8[rdi], 0
	mov	QWORD PTR 16[rdi], 0
	test	rcx, rcx
	je	.L50
	movabs	rax, 4611686018427387903
	cmp	rcx, rax
	ja	.L63
	sal	rcx, 2
	call	_Znwy
.LEHE2:
	jmp	.L64
.L50:
	mov	ebp, 0
	jmp	.L20
.L18:
	mov	QWORD PTR 72[rsp], rdi
	mov	rcx, QWORD PTR 96[rsp]
	test	rcx, rcx
	je	.L25
	call	_ZdlPv
.L25:
	mov	edx, 0
	mov	r9d, 0
	jmp	.L35
.L27:
.LEHB3:
	call	__cxa_rethrow
.LEHE3:
.L58:
	mov	rbx, rax
	call	__cxa_end_catch
	mov	rcx, QWORD PTR 64[rsp]
	test	rcx, rcx
	je	.L32
	call	_ZdlPv
.L32:
	mov	rcx, QWORD PTR 96[rsp]
	test	rcx, rcx
	je	.L47
	call	_ZdlPv
.L47:
	mov	rcx, rbx
.LEHB4:
	call	_Unwind_Resume
.LEHE4:
.L52:
	mov	r9d, 1
	mov	r8d, 0
.L34:
	mov	rcx, QWORD PTR 64[rsp]
	add	rax, QWORD PTR [rcx]
	mov	DWORD PTR [rax], r8d
	add	edx, 1
.L35:
	cmp	edx, esi
	jge	.L51
	movsx	rax, edx
	mov	rcx, QWORD PTR [rbx]
	sal	rax, 2
	mov	rdi, rax
	add	rdi, QWORD PTR [rcx]
	cmp	DWORD PTR [rdi], 0
	jne	.L52
	test	r9b, r9b
	je	.L53
	mov	r8d, 0
	jmp	.L34
.L53:
	mov	r8d, 1
	jmp	.L34
.L51:
	mov	edx, 0
	mov	r8d, 0
	jmp	.L33
.L55:
	mov	r8d, 1
	mov	ecx, 0
.L37:
	add	rax, QWORD PTR 64[rsp]
	mov	rax, QWORD PTR [rax]
	mov	DWORD PTR [rax], ecx
	add	edx, 1
.L33:
	cmp	edx, r13d
	jge	.L54
	movsx	rax, edx
	lea	rcx, [rax+rax*2]
	lea	rax, 0[0+rcx*8]
	mov	rcx, rax
	add	rcx, QWORD PTR [rbx]
	mov	rcx, QWORD PTR [rcx]
	cmp	DWORD PTR [rcx], 0
	jne	.L55
	test	r8b, r8b
	je	.L56
	mov	ecx, 0
	jmp	.L37
.L56:
	mov	ecx, 1
	jmp	.L37
.L54:
	mov	r9d, 1
	jmp	.L36
.L40:
	lea	r8d, -1[rcx]
	movsx	r8, r8d
	mov	r11, QWORD PTR 64[rsp]
	mov	r10, QWORD PTR [r11+rdx]
	lea	edx, -1[r9]
	movsx	rdx, edx
	lea	rdi, [rdx+rdx*2]
	lea	rdx, 0[0+rdi*8]
	mov	rdi, rax
	add	rdi, QWORD PTR [r11+rdx]
	mov	edx, DWORD PTR [rdi]
	add	edx, DWORD PTR [r10+r8*4]
	mov	DWORD PTR [r10+rax], edx
.L41:
	add	ecx, 1
.L42:
	cmp	ecx, esi
	jge	.L39
	movsx	rax, ecx
	movsx	rdx, r9d
	lea	r8, [rdx+rdx*2]
	lea	rdx, 0[0+r8*8]
	mov	r8, rdx
	add	r8, QWORD PTR [rbx]
	sal	rax, 2
	mov	rdi, rax
	add	rdi, QWORD PTR [r8]
	cmp	DWORD PTR [rdi], 0
	je	.L40
	add	rdx, QWORD PTR 64[rsp]
	add	rax, QWORD PTR [rdx]
	mov	DWORD PTR [rax], 0
	jmp	.L41
.L39:
	add	r9d, 1
.L36:
	cmp	r9d, r13d
	jge	.L38
	mov	ecx, 1
	jmp	.L42
.L38:
	mov	eax, DWORD PTR 56[rsp]
	sub	eax, 1
	cdqe
	mov	edx, DWORD PTR 40[rsp]
	sub	edx, 1
	movsx	rdx, edx
	mov	rbx, QWORD PTR 64[rsp]
	lea	rcx, [rdx+rdx*2]
	lea	rdx, 0[0+rcx*8]
	sal	rax, 2
	add	rax, QWORD PTR [rbx+rdx]
	mov	edi, DWORD PTR [rax]
	mov	rsi, QWORD PTR 72[rsp]
	jmp	.L45
.L44:
	add	rbx, 24
.L45:
	cmp	rsi, rbx
	je	.L43
	mov	rcx, QWORD PTR [rbx]
	test	rcx, rcx
	je	.L44
	call	_ZdlPv
	jmp	.L44
.L43:
	mov	rcx, QWORD PTR 64[rsp]
	test	rcx, rcx
	je	.L11
	call	_ZdlPv
.L11:
	mov	eax, edi
	add	rsp, 136
	pop	rbx
	pop	rsi
	pop	rdi
	pop	rbp
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
	.align 4
.LLSDA1915:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT1915-.LLSDATTD1915
.LLSDATTD1915:
	.byte	0x1
	.uleb128 .LLSDACSE1915-.LLSDACSB1915
.LLSDACSB1915:
	.uleb128 .LEHB0-.LFB1915
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1915
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L57-.LFB1915
	.uleb128 0
	.uleb128 .LEHB2-.LFB1915
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L59-.LFB1915
	.uleb128 0x1
	.uleb128 .LEHB3-.LFB1915
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L58-.LFB1915
	.uleb128 0
	.uleb128 .LEHB4-.LFB1915
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSE1915:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT1915:
	.section	.text$_ZN8Solution24uniquePathsWithObstaclesERSt6vectorIS0_IiSaIiEESaIS2_EE,"x"
	.linkonce discard
	.seh_endproc
	.section	.text$_ZSt12__niter_baseIPKiSt6vectorIiSaIiEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE,"x"
	.linkonce discard
	.globl	_ZSt12__niter_baseIPKiSt6vectorIiSaIiEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	.def	_ZSt12__niter_baseIPKiSt6vectorIiSaIiEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt12__niter_baseIPKiSt6vectorIiSaIiEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
_ZSt12__niter_baseIPKiSt6vectorIiSaIiEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE:
.LFB2687:
	.seh_endprologue
	mov	rax, rcx
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1916:
	push	r14
	.seh_pushreg	r14
	push	r13
	.seh_pushreg	r13
	push	r12
	.seh_pushreg	r12
	push	rbp
	.seh_pushreg	rbp
	push	rdi
	.seh_pushreg	rdi
	push	rsi
	.seh_pushreg	rsi
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 112
	.seh_stackalloc	112
	.seh_endprologue
	call	__main
	lea	rsi, ._56[rip]
	mov	QWORD PTR 32[rsp], 0
	mov	QWORD PTR 40[rsp], 0
	mov	QWORD PTR 48[rsp], 0
	mov	ecx, 4
.LEHB5:
	call	_Znwy
.LEHE5:
	mov	QWORD PTR 32[rsp], rax
	lea	rbx, 4[rax]
	mov	QWORD PTR 48[rsp], rbx
	lea	rdx, 4[rsi]
	cmp	rdx, rsi
	je	.L69
	mov	r8d, 4
	mov	rdx, rsi
	mov	rcx, rax
	call	memmove
.L69:
	mov	QWORD PTR 40[rsp], rbx
	lea	rsi, ._57[rip]
	mov	QWORD PTR 56[rsp], 0
	mov	QWORD PTR 64[rsp], 0
	mov	QWORD PTR 72[rsp], 0
	mov	ecx, 4
.LEHB6:
	call	_Znwy
.LEHE6:
	jmp	.L112
.L104:
	mov	rbx, rax
	mov	rcx, QWORD PTR 32[rsp]
	test	rcx, rcx
	je	.L73
	call	_ZdlPv
.L73:
	mov	rcx, rbx
.LEHB7:
	call	_Unwind_Resume
.LEHE7:
.L112:
	mov	QWORD PTR 56[rsp], rax
	lea	rbx, 4[rax]
	mov	QWORD PTR 72[rsp], rbx
	lea	rdx, ._57[rip+4]
	cmp	rdx, rsi
	je	.L75
	mov	r8d, 4
	mov	rdx, rsi
	mov	rcx, rax
	call	memmove
.L75:
	mov	QWORD PTR 64[rsp], rbx
	lea	r12, 32[rsp]
	mov	QWORD PTR 80[rsp], 0
	mov	QWORD PTR 88[rsp], 0
	mov	QWORD PTR 96[rsp], 0
	mov	rdi, r12
	lea	r12, 80[rsp]
	mov	ebx, 48
	mov	rax, rbx
	sar	rax, 3
	movabs	rdx, -6148914691236517205
	imul	rax, rdx
	test	rax, rax
	je	.L113
	movabs	rdx, 768614336404564650
	cmp	rax, rdx
	ja	.L114
	lea	rax, [rax+rax*2]
	lea	rcx, 0[0+rax*8]
.LEHB8:
	call	_Znwy
.LEHE8:
	jmp	.L115
.L113:
	mov	r13d, 0
	jmp	.L77
.L105:
	mov	rbx, rax
	mov	rcx, QWORD PTR 56[rsp]
	test	rcx, rcx
	je	.L79
	call	_ZdlPv
.L79:
	mov	rcx, rbx
.LEHB9:
	call	_Unwind_Resume
.LEHE9:
.L114:
.LEHB10:
	call	_ZSt17__throw_bad_allocv
.LEHE10:
.L106:
	mov	rbx, rax
	jmp	.L93
.L115:
	mov	r13, rax
.L77:
	mov	QWORD PTR 80[rsp], r13
	add	rbx, r13
	mov	QWORD PTR 96[rsp], rbx
	mov	rbx, r13
	jmp	.L86
.L116:
.LEHB11:
	call	_ZSt17__throw_bad_allocv
.L108:
	mov	rcx, rax
	call	__cxa_begin_catch
.L91:
	cmp	rbx, r13
	je	.L89
	mov	rcx, QWORD PTR 0[r13]
	test	rcx, rcx
	je	.L90
	call	_ZdlPv
.L90:
	add	r13, 24
	jmp	.L91
.L117:
	mov	rsi, rax
.L83:
	mov	QWORD PTR [rbx], rsi
	mov	QWORD PTR 8[rbx], rsi
	add	rbp, rsi
	mov	QWORD PTR 16[rbx], rbp
	mov	rcx, QWORD PTR 8[rdi]
	mov	rbp, QWORD PTR [rdi]
	call	_ZSt12__niter_baseIPKiSt6vectorIiSaIiEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	mov	r14, rax
	mov	rcx, rbp
	call	_ZSt12__niter_baseIPKiSt6vectorIiSaIiEEET_N9__gnu_cxx17__normal_iteratorIS5_T0_EE
	mov	rbp, r14
	sub	rbp, rax
	cmp	r14, rax
	je	.L85
	mov	r8, rbp
	mov	rdx, rax
	mov	rcx, rsi
	call	memmove
.L85:
	add	rsi, rbp
	mov	QWORD PTR 8[rbx], rsi
.L82:
	add	rdi, 24
	add	rbx, 24
.L86:
	cmp	r12, rdi
	je	.L81
	test	rbx, rbx
	je	.L82
	mov	rbp, QWORD PTR 8[rdi]
	sub	rbp, QWORD PTR [rdi]
	mov	rcx, rbp
	sar	rcx, 2
	mov	QWORD PTR [rbx], 0
	mov	QWORD PTR 8[rbx], 0
	mov	QWORD PTR 16[rbx], 0
	test	rcx, rcx
	je	.L102
	movabs	rax, 4611686018427387903
	cmp	rcx, rax
	ja	.L116
	sal	rcx, 2
	call	_Znwy
.LEHE11:
	jmp	.L117
.L102:
	mov	esi, 0
	jmp	.L83
.L81:
	mov	QWORD PTR 88[rsp], rbx
	lea	rbx, 80[rsp]
.L87:
	lea	rax, 32[rsp]
	cmp	rbx, rax
	je	.L96
	sub	rbx, 24
	mov	rcx, QWORD PTR [rbx]
	test	rcx, rcx
	je	.L87
	call	_ZdlPv
	jmp	.L87
.L89:
.LEHB12:
	call	__cxa_rethrow
.LEHE12:
.L107:
	mov	rbx, rax
	call	__cxa_end_catch
.L93:
	mov	rcx, QWORD PTR 80[rsp]
	test	rcx, rcx
	je	.L94
	call	_ZdlPv
.L94:
	lea	rsi, 80[rsp]
.L95:
	lea	rax, 32[rsp]
	cmp	rsi, rax
	je	.L98
	sub	rsi, 24
	mov	rcx, QWORD PTR [rsi]
	test	rcx, rcx
	je	.L95
	call	_ZdlPv
	jmp	.L95
.L96:
	lea	rdx, 80[rsp]
	lea	rcx, 111[rsp]
.LEHB13:
	call	_ZN8Solution24uniquePathsWithObstaclesERSt6vectorIS0_IiSaIiEESaIS2_EE
	mov	edx, eax
	mov	rcx, QWORD PTR .refptr._ZSt4cout[rip]
	call	_ZNSolsEi
	mov	rcx, rax
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
.LEHE13:
	jmp	.L118
.L98:
	mov	rcx, rbx
.LEHB14:
	call	_Unwind_Resume
.L103:
	mov	rbx, rax
	lea	rcx, 80[rsp]
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	mov	rcx, rbx
	call	_Unwind_Resume
.LEHE14:
.L118:
	lea	rcx, 80[rsp]
	call	_ZNSt6vectorIS_IiSaIiEESaIS1_EED1Ev
	mov	eax, 0
	add	rsp, 112
	pop	rbx
	pop	rsi
	pop	rdi
	pop	rbp
	pop	r12
	pop	r13
	pop	r14
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
	.align 4
.LLSDA1916:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT1916-.LLSDATTD1916
.LLSDATTD1916:
	.byte	0x1
	.uleb128 .LLSDACSE1916-.LLSDACSB1916
.LLSDACSB1916:
	.uleb128 .LEHB5-.LFB1916
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L104-.LFB1916
	.uleb128 0
	.uleb128 .LEHB6-.LFB1916
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L105-.LFB1916
	.uleb128 0
	.uleb128 .LEHB7-.LFB1916
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB8-.LFB1916
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L106-.LFB1916
	.uleb128 0
	.uleb128 .LEHB9-.LFB1916
	.uleb128 .LEHE9-.LEHB9
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB10-.LFB1916
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L106-.LFB1916
	.uleb128 0
	.uleb128 .LEHB11-.LFB1916
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L108-.LFB1916
	.uleb128 0x1
	.uleb128 .LEHB12-.LFB1916
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L107-.LFB1916
	.uleb128 0
	.uleb128 .LEHB13-.LFB1916
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L103-.LFB1916
	.uleb128 0
	.uleb128 .LEHB14-.LFB1916
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0
	.uleb128 0
.LLSDACSE1916:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT1916:
	.text
	.seh_endproc
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB2693:
	sub	rsp, 40
	.seh_stackalloc	40
	.seh_endprologue
	mov	edx, 65535
	mov	ecx, 1
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	add	rsp, 40
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section .rdata,"dr"
	.align 4
._57:
	.long	1
	.align 4
._56:
	.space 4
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 7.3.0"
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	__cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	__cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	__cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
