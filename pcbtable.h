/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Rusty Dillard
 * @brief This is the header file for the PCBTable class, an array(list) of all PCB elements in the system..
 * @version 0.1
 */
#pragma once

#include "pcb.h"

/**
 * @brief PCTable is an array of all PCB's in the system
 * 
 * @param size: the entire length of the object's table.
 * 
 * @param count: the number of items in the object's table.
 * 
 * @param table: a dynamically allocated block of memory used to store PCB pointers.
 */
class PCBTable {
    //  Members only accessible from within the class.
    private:
        //  Declare a size variable to be used as the PCBTable's length
        int size;

        //  Declare a count variable to be used to keep track of the number of processes in the table.
        int count;

        //  Declare an in dex of PCB pointers to store the PCBs created by the program
        PCB** table;

    //  Members accessible from anywhere the pcbtable.h file is included.
    public:
        PCBTable();
        /**
         * @brief Construct a new PCBTable object of the given size (number of PCBs)
         *
         * @param size: the capacity of the PCBTable
         */
        PCBTable(int size);

        /**
         * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
         *
         */
        ~PCBTable();

        /**
         * @brief Get the PCB at index "idx" of the PCBTable.
         *
         * @param idx: the index of the PCB to get
         * @return PCB*: pointer to the PCB at index "idx"
         */
        PCB* getPCB(unsigned int idx);

        /**
         * @brief Overload of the operator [] that returns the PCB at idx
         *
         * @param idx
         * @return PCB*
         */
        PCB *operator[](unsigned int idx) {
            return getPCB(idx);
        }

        /**
         * @brief Add a PCB to the PCBTable at index idx.
         *
         * @param pcb: the PCB to add
         * @param idx: the index to add the PCB at
         */
        void addPCB(PCB *pcb, unsigned int idx);

        /**
         * @brief Add a new PCB to the PCBTable.
         * @param pid Id of the new PCB
         * @param priority Priority of the new PCB
         * @param idx The index of the new PCB in the PCBTable
         */
        void addNewPCB(unsigned int pid, unsigned int priority, unsigned int idx) {
            PCB *pcb = new PCB(pid, priority);
            addPCB(pcb, idx);
        }
};