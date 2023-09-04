# MorganSafe_Encryption_Decryption
This Git repo contains a C++ encryption/decryption module for Android apps (Morgan Safe), using biometric authentication for secure file access. Features include AES encryption, optimized performance,  and comprehensive error handling and logging. 

# Welcome to the organSafe_Encryption_Decryption repository!

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [Contact](#contact)

## Getting Started

These instructions will help you get a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

- C/C++ compiler installed
- Code Editor <any choice is ok>
  
### Installation

1. Choose and install the code Editor of your choice
2. Install C compiler on the machine from https://www.mingw-w64.org/downloads/
3. If using VS Code install code runner extension
4. If using VS Code, Go to settings, search terminal and check box "Run code in terminal"

## Usage

The module automatically encrypts given information on call from a triggering application. It also decrypts certain information on call from another triggering application.

- encryption.cpp - this file contains a naive approach to encrypting a stream of data read from a file. This file also dynamically allocates an encryption key and lock that can be accessed by the decryption file later upon decryption
- decryption.cpp - this file contains a  naive way of decrypting a stream of data read from a file using a dynamically allocated key from the encryption module

## Contributing

We welcome contributions from the community! If you'd like to contribute to Trade_It!, please follow these steps:

1. Fork this repository.
2. Create a new branch: `git checkout -b feature/your-feature-name`.
3. Make your changes and commit them: `git commit -m 'Add some feature'`.
4. Push to the branch: `git push origin feature/your-feature-name`.
5. Open a pull request explaining your changes.

## Contact
- goshomip@gmail.com or https://web.groupme.com/contact/103653571/4OWCyvi9
- Thank you for your interest in MorganSafe_Encryption_Decryption. We hope you find it useful and we look forward to your contributions.
