/*---------------------------------------------------------------------------*\
     ██╗████████╗██╗  ██╗ █████╗  ██████╗ █████╗       ███████╗██╗   ██╗
     ██║╚══██╔══╝██║  ██║██╔══██╗██╔════╝██╔══██╗      ██╔════╝██║   ██║
     ██║   ██║   ███████║███████║██║     ███████║█████╗█████╗  ██║   ██║
     ██║   ██║   ██╔══██║██╔══██║██║     ██╔══██║╚════╝██╔══╝  ╚██╗ ██╔╝
     ██║   ██║   ██║  ██║██║  ██║╚██████╗██║  ██║      ██║      ╚████╔╝
     ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝      ╚═╝       ╚═══╝

 * In real Time Highly Advanced Computational Applications for Finite Volumes
 * Copyright (C) 2017 by the ITHACA-FV authors
-------------------------------------------------------------------------------

  License
  This file is part of ITHACA-FV

  ITHACA-FV is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  ITHACA-FV is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with ITHACA-FV. If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/
#ifndef Tm_time_H
#define Tm_time_H
#include <string>
#include <iostream>
#include <math.h>
#include <Eigen/Eigen>
#include <sys/stat.h>
#include "fvCFD.H"
#include "ITHACAstream.H"
#include "FofM.H"

class Tm_time : public FofM
{
    public:
        //constructors
        Tm_time();
        Tm_time(int argc, char* argv[], label Nsampled);
        ~Tm_time() {};

        //Members
        /// List of pointers to temperature field
        autoPtr<volScalarField> _T;


        //Methods
        /// Method that computes the average temperature (integral average) for the snapshot number t (starting from 0),
        /// output are sought in dir/0, dir/1, dir/2, etc... i.e solution correspondent to
        /// 0th,1st,2nd etc... parameters set passed to FOM/ROM
        void buildMO(std::string dir, label t);
};

#endif
