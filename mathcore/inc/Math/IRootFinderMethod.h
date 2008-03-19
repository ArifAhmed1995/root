// @(#)root/mathcore:$Id$
// Authors: David Gonzalez Maline    01/2008 

/**********************************************************************
 *                                                                    *
 * Copyright (c) 2006 , LCG ROOT MathLib Team                         *
 *                                                                    *
 *                                                                    *
 **********************************************************************/

// Header for the IRootFinderMethod interface
// 
// Created by: David Gonzalez Maline  : Fri Jan 25 2008
// 

#ifndef ROOT_Math_IRootFinderMethod
#define ROOT_Math_IRootFinderMethod

#ifndef ROOT_Math_Error
#include "Math/Error.h"
#endif

#include <Math/IFunction.h>

namespace ROOT {
namespace Math {

//___________________________________________________________________________________________
/**
   Interface for finding function roots.

   @ingroup RootFind
  
 */

class IRootFinderMethod {
public:
   /** Default Destructor. */
   virtual ~IRootFinderMethod() {}

   /** Default Constructor. */
   IRootFinderMethod() {}
   
   // Common functionality

   /** Sets the function for algorithms using derivatives.  */
   virtual int SetFunction(const ROOT::Math::IGradFunction&, double)
   {
      MATH_ERROR_MSG("SetFunction", "This method must be used with a Root Finder algorithm using derivatives");
      return -1;
   }

   /** Sets the function for the rest of the algorithms.
       The parameters set the interval where the root has to be calculated. */
   virtual int SetFunction(const ROOT::Math::IGenFunction& , double , double )
   {
      MATH_ERROR_MSG("SetFunction", "Algorithm requires derivatives");
      return -1;
   }

   /** Returns the previously calculated root. */
   virtual double Root() const = 0;

   // Methods to be Implemented in the derived classes

   /** Stimates the root for the function.  
       \@param maxIter maximum number of iterations.
       \@param absTol desired absolute error in the minimum position.
       \@param absTol desired relative error in the minimum position.
   */
   virtual int Solve(int maxIter = 100, double absTol = 1E-3, double relTol = 1E-6) = 0;

   /** Return name of root finder algorithm */
   virtual const char* Name() const = 0;
   
   /** This method is not implemented. They are here to accomplish with the GSLRootFinder 
       and GSLRootFinderDeriv classes and will return an error if it's not one of them. */
   virtual int Iterate() {
      MATH_ERROR_MSG("Iterate", "This method must be used with a Root Finder algorithm wrapping the GSL Library");
      return -1;
   }

   /** This method is not implemented. They are here to accomplish with the GSLRootFinder 
       and GSLRootFinderDeriv classes and will return an error if it's not one of them. */
   virtual int Iterations() const {
      MATH_ERROR_MSG("Iterations", "This method must be used with a Root Finder algorithm wrapping the GSL Library");
      return -1;
   }

};

} // namespace Math
} // namespace ROOT


#endif /* ROOT_Math_IRootFinderMethod */
