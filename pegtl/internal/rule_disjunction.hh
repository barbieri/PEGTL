// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef PEGTL_INTERNAL_RULE_DISJUNCTION_HH
#define PEGTL_INTERNAL_RULE_DISJUNCTION_HH

#include "../apply_mode.hh"

namespace pegtl
{
   namespace internal
   {
      template< typename ... Rules >
      struct rule_disjunction
      {
         template< apply_mode A, template< typename ... > class Action, template< typename ... > class Control, typename Input, typename ... States >
         static bool match( Input & in, States && ... st )
         {
            bool result = false;
            using swallow = bool[];
            (void)swallow{ result = result || Control< Rules >::template match< A, Action, Control >( in, st ... )..., true };
            return result;
         }
      };

   } // internal

} // pegtl

#endif
