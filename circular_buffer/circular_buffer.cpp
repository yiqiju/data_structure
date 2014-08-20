// Implement a circular buffer

#include <stdio.h>

static const size_t MAX_SAMPLE_SIZE = 30;

// Buffer class, use struct to create. Is it cool?
struct Circular_buffer
{
   int64_t array[MAX_SAMPLE_SIZE]; // Circular buffer
   size_t counter;                 // Number of the elements in the buffer
   size_t current_index;           // The index of the last pushed element

   // This operator allows to locate the element reference to the
   // circular buffer current_index in a reverse order
   // eg.
   //  0 1 2 3 4 5 6 7 8
   // ------------------
   // |j|k|c|d|e|f|g|h|i
   //
   // current_index = 1, to locate absoluted 7 from current_index:
   // m_sample_list[3] = h
   int64_t operator[](size_t);
}m_sample_list;

// /////////////////////////////////////////////////////////////////////////////
// This is where the magic happens. Given the current index, Locate the Nth
// element that is to the left of current index. Whether wraps or not, it works!
// /////////////////////////////////////////////////////////////////////////////
int64_t Circular_buffer::operator[](size_t relative_index)
{
   // relative_index start from the current position and goes backward
   // current index is based on the absolute array position
   ASSERT(relative_index < MAX_SAMPLE_SIZE);

   size_t ret_index = 0;
   if (relative_index <= current_index)
   {
      ret_index = current_index - relative_index;
   }
   else
   {
      ret_index = MAX_SAMPLE_SIZE - (relative_index - current_index);
   }

   return array[ret_index];
}

