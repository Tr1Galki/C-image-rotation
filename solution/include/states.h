#ifndef STATES_H
#define STATES_H


/*  deserializer   */
enum read_status {
  READ_OK = 0,
  READ_INVALID_SIGNATURE,
  READ_INVALID_BITS,
  READ_INVALID_HEADER,
  READ_ERROR
  /* коды других ошибок  */
  };


/*  serializer   */
enum write_status {
  WRITE_OK = 0,
  WRITE_ERROR
  /* коды других ошибок  */
};

enum memory_status {
  ALLOCATE_MEMORY_OK = 0,
  ALLOCATE_MEMORY_ERROR
};


#endif