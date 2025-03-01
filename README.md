# Multi-Threading Implementation (Four Phases)

## Overview
This project demonstrates multi-threading concepts and synchronization through four progressive phases. Each phase builds upon the previous one to showcase thread operations, resource protection, deadlock scenarios, and deadlock resolution. A banking system example is used, but the principles can be applied to other scenarios.

## Build and Run Instructions

### Prerequisites
Ensure you have the following installed:
- **GCC** (for compiling C/C++ code)
- **Make** (for build automation)
- **CMake** (if using C++)
- **Rust** (if using Rust for threading implementation)

### Installation
```bash
sudo apt update
sudo apt install build-essential cmake
```

### Building the Project
If using **C/C++**:
```bash
make
```

### Running the Program
For C/C++:
```bash
./multi_threading_demo
```

## Project Phases

### Phase 1: Basic Thread Operations
- Create and manage threads.
- Demonstrate basic thread safety principles.
- **Banking Example:** Implement threads handling individual transactions.

### Phase 2: Resource Protection
- Implement **mutex locks** for shared resource protection.
- Ensure synchronized access to shared data.
- **Banking Example:** Protect account access with mutexes to prevent race conditions.

### Phase 3: Deadlock Creation
- Simulate multiple resource locks.
- Demonstrate deadlock scenarios.
- Implement **deadlock detection**.
- **Banking Example:** Simulate deadlock in multi-account transfers.

### Phase 4: Deadlock Resolution
- Implement **timeout mechanisms**.
- Add **proper resource ordering**.
- Prevent and recover from deadlocks.
- **Banking Example:** Resolve deadlocks by enforcing an ordered account access approach.

## Dependencies
- **pthread** (for C/C++ thread management)
- **std::thread** (for C++ threading)
- **Rust standard library threads** (if using Rust)
- **CMake** (for C++ projects)
- **Cargo** (for Rust projects)

Install dependencies:
```bash
sudo apt install cmake
```
