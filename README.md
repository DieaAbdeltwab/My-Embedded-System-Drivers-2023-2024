# ⚡ Embedded Systems Drivers Collection

<div align="center">

![Embedded Systems](https://img.shields.io/badge/Embedded-Systems-FF6B6B?style=for-the-badge&logo=arm&logoColor=white)
![AVR](https://img.shields.io/badge/AVR-ATmega32-00979D?style=for-the-badge&logo=atmel&logoColor=white)
![STM32](https://img.shields.io/badge/STM32-Drivers-03234B?style=for-the-badge&logo=stmicroelectronics&logoColor=white)
![ARM Cortex-M](https://img.shields.io/badge/ARM-Cortex--M-E34F26?style=for-the-badge&logo=arm&logoColor=white)

**⚙️ Professional AVR & STM32 MCAL & HAL drivers built from scratch 🚀**

*No HAL Libraries • No CubeMX • Pure Register-Level Programming*

</div>

---

## 🔥 **The Journey**

<div align="center">
<img src="https://media.giphy.com/media/SWoSkN6DxTszqIKEqv/giphy.gif" width="400"/>
</div>

From Arduino enthusiast to ARM bare-metal expert — **4 years of embedded mastery!**

| Year | Journey Stage | What I Learned |
|------|--------------|----------------|
| **2021** 🌱 | **The Beginning** | Started with Arduino & ESP32 - Built my first IoT projects |
| **2022** 🚀 | **AVR Mastery** | Took AVR course - Learned microcontroller architecture deeply |
| **2023** ⚡ | **ARM Revolution** | Took ARM course - Entered the world of Cortex-M processors |
| **2024** 💎 | **Production Ready** | Built professional projects - V2X system, Bootloaders, complete driver libraries |

---

## 📦 **What's Inside?**

This repository contains **production-ready embedded drivers** built entirely from scratch during 2022-2024.

### **🎯 Four Complete Development Platforms**

```
📁 My-Embedded-System-Drivers-2023-2024/
│
├── 🟡 ATmega32                (AVR 8-bit - ATmega32)
├── 💙 BLUEPILL-F103          (STM32F103C8T6 - Cortex-M3)
├── 🔷 DISCOVERY-F429ZI       (STM32F429ZIT6 - Cortex-M4)
└── 🎯 NUCLEO-F411RE          (STM32F411RET6 - Cortex-M4)
```

### **🏗️ Clean Layered Architecture**

#### **ATmega32 - 4-Layer AVR Architecture**
```
📂 ATmega32/
│
├── 📚 0-LIB Layer         → Standard types, bit operations, utilities
├── ⚙️ 1-MCAL Layer        → Microcontroller peripherals (DIO, ADC, UART, etc.)
├── 🔌 2-HAL Layer         → Hardware modules (LCD, Keypad, Sensors, etc.)
└── 📄 main.c              → Your application starts here
```

#### **STM32 Boards - 5-Layer ARM Architecture**
```
📂 STM32-Board-Folder/
│
├── 📚 0-LIB Layer         → Standard types, bit operations, utilities
├── 🧠 1-CORE Layer        → ARM Cortex-M core (NVIC, SCB, SysTick)
├── ⚙️ 2-MCAL Layer        → Microcontroller peripherals
├── 🔌 3-HAL Layer         → Hardware modules (LCD, Sensors, etc.)
├── 🎛️ 4-SERVICES Layer    → Application services & protocols
└── 📄 main.c              → Your application starts here
```

---

## 🛠️ **AVR ATmega32 Drivers**

<div align="center">

### **MCAL Layer - Microcontroller Abstraction**

</div>

| Driver | What It Does | Status |
|--------|-------------|--------|
| **DIO** | Digital I/O control - LEDs, buttons, pins | ✅ Complete |
| **ADC** | Analog to digital conversion | ✅ Complete |
| **UART** | Serial communication (TX/RX) | ✅ Complete |
| **SPI** | High-speed peripheral interface | ✅ Complete |
| **I2C (TWI)** | Two-wire communication protocol | ✅ Complete |
| **TIMER0** | 8-bit timer/counter with PWM | ✅ Complete |
| **TIMER1** | 16-bit timer/counter with PWM | ✅ Complete |
| **TIMER2** | 8-bit async timer with PWM | ✅ Complete |
| **EXTI** | External interrupts | ✅ Complete |
| **WDT** | Watchdog timer | ✅ Complete |


## 🛠️ **STM32 MCAL Drivers Collection**

<div align="center">

**Complete peripheral drivers written at register level!**

</div>

| Driver | What It Does | Status |
|--------|-------------|--------|
| **GPIO** | Digital I/O control - LEDs, buttons, pins | ✅ Complete |
| **RCC** | Clock configuration & peripheral power | ✅ Complete |
| **EXTI** | External interrupts & events | ✅ Complete |
| **AFIO** | Pin remapping & alternate functions | ✅ Complete |
| **USART** | Serial communication (TX/RX) | ✅ Complete |
| **SPI** | High-speed peripheral interface | ✅ Complete |
| **I2C** | Two-wire communication protocol | ✅ Complete |
| **GPTIMER** | PWM, timers, input capture | ✅ Complete |
| **ADC** | Analog to digital conversion | ✅ Complete |
| **DMA** | Direct memory access transfers | ✅ Complete |

---

## 🎮 **Supported Hardware**

<div align="center">

### **Development Boards**

</div>

| Board | Architecture | Chip | Flash | RAM | Price |
|-------|-------------|------|-------|-----|-------|
| **ATmega32** | AVR 8-bit | ATmega32 | 32KB | 2KB | ~$3 💰 |
| **Blue Pill** | ARM Cortex-M3 | STM32F103C8T6 | 64KB | 20KB | ~$2 💰 |
| **Discovery F429** | ARM Cortex-M4 | STM32F429ZIT6 | 2MB | 256KB | ~$40 💰 |
| **Nucleo F411** | ARM Cortex-M4 | STM32F411RET6 | 512KB | 128KB | ~$15 💰 |

*All drivers tested on real hardware - no simulation!*

---

## 💡 **Why These Drivers?**

<div align="center">
<img src="https://media.giphy.com/media/l0HlNaQ6gWfllcjDO/giphy.gif" width="300"/>
</div>

### **🎯 Philosophy**

✅ **No Black Box Code** - Understand every bit operation  
✅ **Production Quality** - Used in real graduation projects  
✅ **Educational** - Learn how microcontrollers really work  
✅ **Portable** - Easy to adapt to other AVR/STM32 families  
✅ **Lightweight** - No bloated libraries or overhead  

### **👨‍💻 Perfect For**

🎓 **Students** - Learning embedded systems the right way  
⚡ **Engineers** - Reference for professional projects  
🔧 **Makers** - Building real embedded applications  
📚 **Educators** - Teaching bare-metal programming  

---

## 🚀 **Featured Projects Built With These Drivers**

### **🚗 [V2X Vehicle-to-Everything System](https://github.com/DieaAbdeltwab/V2X)**
> **Graduation Project - Excellence Grade ⭐**

My final year project combining multiple technologies:
- Real-time vehicle communication (V2I, V2P, V2G)
- GPS tracking synced to Firebase cloud
- AI accident detection with Raspberry Pi
- Beautiful TFT dashboard interface
- ESP32 WiFi connectivity

**Built using:** STM32F411, Custom drivers from this repo, ESP32, GPS, TFT

---

### **🔥 [Bootloader V1.0](https://github.com/DieaAbdeltwab/Bootloader)**
> **Professional Firmware Update System**

Complete bootloader implementation with:
- Flash memory management
- Multiple application switching
- Security features (RDP, CRC)
- LVGL graphical interface
- UART-based firmware upload

**Built using:** STM32F429, All custom MCAL drivers (GPIO, RCC, UART, FLASH, CRC)

---

### **🤖 [Robot V1.0](https://github.com/DieaAbdeltwab/Robot-AVR-)**
> **Multi-Mode Autonomous System**

Smart robot with multiple operation modes:
- Manual remote control
- Line following algorithm
- Obstacle avoidance
- Position tracking

**Built using:** AVR ATmega32, Custom AVR drivers

---

### **🔢 [Simple Calculator](https://github.com/DieaAbdeltwab/Simple-Calculator)**
> **Embedded Calculator System**

Full-featured calculator with keypad and LCD display.

**Built using:** AVR ATmega32

---

### **🐍 [Snake Game - Pixel Edition](https://github.com/DieaAbdeltwab/Snake-Game-Pixel-)**
> **Classic Game on Microcontroller**

Fully functional Snake game running on embedded hardware!

**Built using:** Custom display drivers

---

## 📊 **Technical Stack**

<div align="center">
<img src="https://media.giphy.com/media/3o7qE1YN7aBOFPRw8E/giphy.gif" width="300"/>
</div>

### **🛠️ Tools & Environment**

| Tool | Purpose |
|------|---------|
| **Atmel Studio** | AVR development IDE |
| **STM32CubeIDE** | STM32 development IDE |
| **Visual Studio Code** | Code editing |
| **Logic Analyzer** | Protocol debugging |
| **STM32CubeProgrammer** | Flashing firmware |

### **📚 My Learning Path**

✅ **IMT AVR Embedded Systems** (June 2022)  
✅ **IMT ARM Embedded Systems** (January 2023)  
✅ **Advanced Embedded Diploma** by Amgad Samir (May 2023)  
✅ **Mastering Embedded Systems** by Keroles Shenouda (December 2023)  

---

## 🎓 **Academic Background**

**Electronics and Communication Engineering**  
*Fayoum University (2019-2024)*

- 📊 **Degree:** Very Good
- 🏆 **Graduation Project:** Excellence (V2X Embedded System)
- 💡 **Focus:** Embedded Systems, Low-level Programming, Hardware-Software Integration

---

## 🌟 **Project Highlights**

### **What Makes This Special?**

1. **🎯 Real Project Experience** - Not just tutorials, actual working projects
2. **⚡ Register-Level Mastery** - Direct hardware manipulation, no abstractions
3. **🏗️ Professional Architecture** - Industry-standard layered design
4. **📖 Well Documented** - Every driver explained with comments
5. **✅ Hardware Tested** - All code verified on physical boards

### **📈 By The Numbers**

- **70+** Individual drivers written
- **4** Different microcontroller platforms supported
- **4** Years of embedded systems experience
- **5** Major projects completed
- **15+** Peripheral types covered

---

## 🔧 **Quick Start**

### **1️⃣ Clone This Repository**

```bash
git clone https://github.com/DieaAbdeltwab/My-Embedded-System-Drivers-2023-2024.git
```

### **2️⃣ Choose Your Platform**

Pick the folder matching your hardware:
- `ATmega32` for AVR ATmega32 microcontroller
- `BLUEPILL-F103` for Blue Pill boards
- `DISCOVERY-F429ZI` for Discovery boards
- `NUCLEO-F411RE` for Nucleo boards

### **3️⃣ Open & Build**

Open in your IDE (Atmel Studio for AVR, STM32CubeIDE for STM32), compile, and flash!

### **4️⃣ Start Building**

Use the drivers as building blocks for your own embedded projects!

---

## 📖 **Documentation Style**

Each driver includes:

📄 **Header Files** - Public API and configuration  
📄 **Source Files** - Implementation with detailed comments  

---

## 💬 **Connect With Me**

<div align="center">

[![GitHub](https://img.shields.io/badge/GitHub-DieaAbdeltwab-181717?style=for-the-badge&logo=github)](https://github.com/DieaAbdeltwab)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-dieaabdeltwab-0077B5?style=for-the-badge&logo=linkedin)](https://linkedin.com/in/dieaabdeltwab)
[![Email](https://img.shields.io/badge/Email-Contact-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:dieaabdeltwab2024@gmail.com)

</div>

---

## 🏆 **Achievements**

✨ **Graduation Project:** Excellence Grade  
✨ **Professional Bootloader:** Complete implementation  
✨ **V2X System:** Multi-technology integration  
✨ **70+ Drivers:** All tested and working  
✨ **Production Quality:** Used in real applications  

---

<div align="center">

### **⭐ If you found this helpful, star this repository! ⭐**

---

**Built with 💙 by an embedded systems enthusiast**

*"Understanding hardware at the register level is the foundation of true embedded mastery"*

---

![Visitors](https://visitor-badge.laobi.icu/badge?page_id=DieaAbdeltwab.My-Embedded-System-Drivers)
![GitHub Stars](https://img.shields.io/github/stars/DieaAbdeltwab/My-Embedded-System-Drivers-2023-2024?style=social)
![GitHub Forks](https://img.shields.io/github/forks/DieaAbdeltwab/My-Embedded-System-Drivers-2023-2024?style=social)

**© 2022-2024 Diea Abdeltwab | Embedded Systems Engineer**

</div>
