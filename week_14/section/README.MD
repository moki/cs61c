## Section 13

Virtual Memory and IO

```
./section-13.pdf
```

## 1. Virtual Memory

### 1.1

What are three specific benefits of using virtual memory?

```
1. use more virtual memory than RAM available.

2. security, each process has own virtual memory space
   keep programs from messing with each other's memory.

3. Fill holes in RAM address space, in the allocation process.
```

### 1.2

What should happen to the TLB when a new value is loaded into the page table address register?

```
invalidate old page tlb entries.
```

### 1.3

A processor has 16-bit addresses, 256 byte pages, and an 8-entry fully associative TLB
with LRU replacement (the LRU field is 3 bits and encodes the order in which pages were
accessed, 0 being the most recent).

At some time instant, the TLB for the current process
is the initial state given in the table below. Assume that all current page table entries are
in the initial TLB.

Assume also that all pages can be read from and written to. Fill in the
final state of the TLB according to the access pattern below.

```
Initial	TLB:					Final TLB State:

VPN 	PPN 	Valid 	Dirty 	LRU		VPN 	PPN 	Valid 	Dirty 	LRU
0x01 	0x11 	1 	1 	0		0x01 	0x11 	1 	1 	6
0x00 	0x00 	0 	0 	7		0x13 	0x17 	1 	1 	4
0x10 	0x13 	1 	1 	1		0x10 	0x13 	1 	1 	7
0x20 	0x12 	1 	0 	5		0x20 	0x12 	1 	1 	1
0x00 	0x00 	0 	0 	7		0x23 	0x18 	1 	1 	2
0x11 	0x14 	1 	0 	4		0x11 	0x14 	1 	0 	5
0xac 	0x15 	1 	1 	2		0xac 	0x15 	1 	1 	7
0xff 	0x16 	1 	0 	3		0x34 	0x19 	1 	1 	0

Access	pattern:
Read 	0x11f0
Write 	0x1301
Write 	0x20ae
Write 	0x2332
Read 	0x20ff
Write 	0x3415

```

## 2. IO

### 2.1 Fill this table of polling and interrupts.

```
Operation 	Definition 		Pro 			Con

Polling		Sampling actively	simple implementation.	synchronous
		of an external device	low latency.		clock cycle waste heavy.
		by a client		low overhead.
		synchronously.		good in the situation
					when client can't make
					progress until device
					ready.

Interrupts	signal emitted to the	asynchronous		complex
		CPU by the hardware or	eliminates unproductive	higher latency overhead
		software indicating	waiting time in polling	(interrupt handler)
		(that device ready)	loops, waiting for
		that there is event	external events.
		that needs immediate
		attention.

```

### 2.2 Memory Mapped I/O.

Certain memory addresses correspond to registers in I/O devices and not normal
memory.

0xFFFF0000 – Receiver Control:
LSB is the ready bit, there may be other bits set that we don’t need right now.

0xFFFF0004 – Receiver Data:
Received data stored at lowest byte.

0xFFFF0008 – Transmitter Control:
LSB is the ready bit, there may be other bits set that we don’t need right now.

0xFFFF000C – Transmitter Data:
Transmitted data stored at lowest byte

Write RISC-V code to read a byte from the receiver and immediately send it to the
transmitter.

```
			lui  t0, 0xffff			# load memmory mapped I/O address

receiver_poll:		lw   t1, 0(t1)			# wait for the
			andi t1, t1, 0x1		# receiver
			beq  t1, x0, receiver_poll	# "ready" state

			lb   t2, 4(t0)			# load data from the receiver

transmitter_poll:	lw   t1, 8(t0)			# wait for the
			andi t1, t1, 0x1		# transmitter
			beq  t1, x0, transmitter_poll	# "ready" state
			sb   t2, 12(t0)			# write data to the transmitter device
```