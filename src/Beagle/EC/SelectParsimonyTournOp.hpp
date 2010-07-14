/*
 *  Open BEAGLE
 *  Copyright (C) 2001-2007 by Christian Gagne and Marc Parizeau
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact:
 *  Laboratoire de Vision et Systemes Numeriques
 *  Departement de genie electrique et de genie informatique
 *  Universite Laval, Quebec, Canada, G1K 7P4
 *  http://vision.gel.ulaval.ca
 *
 */

/*!
 *  \file   Beagle/EC/SelectParsimonyTournOp.hpp
 *  \brief  Definition of the class SelectParsimonyTournOp.
 *  \author Christian Gagne
 *  \author Marc Parizeau
 *  $Revision: 1.8 $
 *  $Date: 2007/08/17 18:09:13 $
 */

#ifndef Beagle_EC_SelectParsimonyTournOp_hpp
#define Beagle_EC_SelectParsimonyTournOp_hpp

#include <string>

#include "Beagle/Core.hpp"
#include "Beagle/EC/SelectionOp.hpp"


namespace Beagle
{
	
namespace EC
{

/*!
 *  \class SelectParsimonyTournOp Beagle/EC/SelectParsimonyTournOp.hpp
 *     "Beagle/EC/SelectParsimonyTournOp.hpp"
 *  \brief Lexicographic parsimony pressure tournament selection operator class.
 *  \ingroup EC
 *  \ingroup Op
 *
 *  A simple lexicographic parsimony pressure tournament selection operator, based an idea
 *  presented in: Luke, S., and L. Panait. 2002. Lexicographic Parsimony Pressure. In GECCO-2002:
 *  Proceedings of the Genetic and Evolutionary Computation Conference. W. B. Langdon et al, eds.
 *  Morgan Kauffman. 829-836.
 *
 */
class SelectParsimonyTournOp : public Beagle::EC::SelectionOp
{

public:

	//! SelectParsimonyTournOp allocator type.
	typedef Beagle::AllocatorT<SelectParsimonyTournOp,Beagle::EC::SelectionOp::Alloc> Alloc;
	//! SelectParsimonyTournOp handle type.
	typedef Beagle::PointerT<SelectParsimonyTournOp,Beagle::EC::SelectionOp::Handle> Handle;
	//! SelectParsimonyTournOp bag type.
	typedef Beagle::ContainerT<SelectParsimonyTournOp,Beagle::EC::SelectionOp::Bag> Bag;

	explicit SelectParsimonyTournOp(std::string inReproProbaName="ec.repro.prob",
	                                std::string inName="SelectParsimonyTournOp");
	virtual ~SelectParsimonyTournOp()
	{ }

	virtual void         registerParams(Beagle::System& ioSystem);
	virtual unsigned int selectOneIndividual(Beagle::Individual::Bag& ioPool, Beagle::Context& ioContext);

protected:

	Beagle::UInt::Handle mNumberParticipants;  //!< Number of participants to each tournament.

};

}

}

#endif // Beagle_EC_SelectParsimonyTournOp_hpp
