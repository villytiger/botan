/*
* CBC-MAC
* (C) 1999-2007 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_CBC_MAC_H__
#define BOTAN_CBC_MAC_H__

#include <botan/mac.h>
#include <botan/block_cipher.h>

namespace Botan {

/**
* CBC-MAC
*/
class BOTAN_DLL CBC_MAC : public MessageAuthenticationCode
   {
   public:
      std::string name() const;
      MessageAuthenticationCode* clone() const;
      size_t output_length() const { return e->block_size(); }
      void clear();

      Key_Length_Specification key_spec() const
         {
         return e->key_spec();
         }

      /**
      * @param cipher the underlying block cipher to use
      */
      CBC_MAC(BlockCipher* cipher);
      ~CBC_MAC();
   private:
      void add_data(const byte[], size_t);
      void final_result(byte[]);
      void key_schedule(const byte[], size_t);

      BlockCipher* e;
      secure_vector<byte> state;
      size_t position;
   };

}

#endif
