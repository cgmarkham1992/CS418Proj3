// Mark Moss - Wednesday, January 28, 2015
// CS 418 - Operating Systems
// Lab #3 - Virtual Memory Management System

// --------------------------------------------------------------
// STARTING SHELL
// --------------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// ------------------------------------------------------------
// Key System Parameters 
// ------------------------------------------------------------

#define COMMAND_SIZE 200
#define WORD_SIZE 100

#define ADDRESS_SPACE_SIZE 100
#define PAGE_SIZE 10
#define NUM_PROCESSES 4
#define NUM_FRAMES 4

// ------------------------------------------------------------
// Interpreter Loop & Diagnostic Interfaces
// ------------------------------------------------------------

bool messages = true;
int startup_memory_system();
void display_warning(char *warning_input);
bool process_next_command();

// ------------------------------------------------------------
// Memory Management Data Structures (Global Variables)
// ------------------------------------------------------------


// --------------------------------------------------------------
// Memory Management Supporting Procedures & Functions
// --------------------------------------------------------------


// ------------------------------------------------------------
// main() Procedure
// ------------------------------------------------------------

int main() {
	// declare the required data structures
	char *word_ptr;
	bool keep_going = true;

	// initialize and start the file system data structures
	startup_memory_system();
	display_warning("main: memory manager started");

	// accept and process user commands until directed to stop
	do {
		keep_going = process_next_command();
	} while (keep_going);

	display_warning("main: memory manager stopped");
	return 0;
}

// ------------------------------------------------------------
// User Interface Layer Procedures & Functions (Your Homework)
// ------------------------------------------------------------

void mem_begin(int pid) { }

void mem_read(int pid, int address) { }

void mem_write(int pid, int address) { }

void mem_end(int pid) { }

void view_memory_system() { }

// ------------------------------------------------------------
// Interpreter Loop & Diagnostic Procedures & Functions
// ------------------------------------------------------------

int startup_memory_system() {
	return 1;
}

void display_warning(char *warning_input) {
	if (messages) { printf(" sys !> %s\n", warning_input); }
}

bool process_next_command() {
	char command[COMMAND_SIZE + 1];
	int pid, address;

	printf("\nrequest: > ");
	fgets(command, sizeof command, stdin);

	// process the entered command
	if (sscanf(command, "begin p%d", &pid) == 1) {
		mem_begin(pid);

	} else if (sscanf(command, "read p%d %d", &pid, &address) == 2) {
		mem_read(pid, address);

	} else if (sscanf(command, "write p%d %d", &pid, &address) == 2) {
		mem_write(pid, address);

	} else if (sscanf(command, "end p%d", &pid) == 1) {
		mem_end(pid);

	} else if (strncmp(command, "view", 4) == 0) {
		view_memory_system();

	} else if (strncmp(command, "warnings", 8) == 0) {
		if (messages) { printf(" sys !> warnings have been turned off\n"); }
			else { printf(" sys !> warnings are on\n"); }
		messages = !messages;

	} else if (strncmp(command, "stop", 4) == 0) {
		return false;

	} else {
		display_warning("main: unrecognized command");
	}

	return true;
}
