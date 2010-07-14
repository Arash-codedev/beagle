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
 *  \file   Beagle/EC/PackageBase.cpp
 *  \brief  Source code of class PackageBase.
 *  \author Christian Gagne
 *  $Revision: 1.8 $
 *  $Date: 2007/09/20 14:46:33 $
 */

#include "Beagle/EC.hpp"

using namespace Beagle;
using namespace Beagle::EC;


/*!
 *  \brief Construct package with basic Open BEAGLE objects.
 */
Beagle::EC::PackageBase::PackageBase(void) :
		Package("EC-PackageBase")
{ }


/*!
 *  \brief Configure system by adding necessary components into it.
 *  \param ioSystem System to configure.
 */
void Beagle::EC::PackageBase::configure(System& ioSystem)
{
	Beagle_StackTraceBeginM();
	Factory& lFactory = ioSystem.getFactory();

	// Add available basic types to the factory
	lFactory.insertAllocator("Beagle::EC::AdaptBreedingProbaOp", new AdaptBreedingProbaOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::AlgoGenerational", new AlgoGenerational::Alloc);
	lFactory.insertAllocator("Beagle::EC::AlgoSequential", new AlgoSequential::Alloc);
	lFactory.insertAllocator("Beagle::EC::AlgoSteadyState", new AlgoSteadyState::Alloc);
	lFactory.insertAllocator("Beagle::EC::DecimateOp", new DecimateOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::FitnessSimple", new FitnessSimple::Alloc);
	lFactory.insertAllocator("Beagle::EC::FitnessSimpleMin", new FitnessSimpleMin::Alloc);
	lFactory.insertAllocator("Beagle::EC::GenerationalOp", new GenerationalOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::HierarchicalFairCompetitionOp", new HierarchicalFairCompetitionOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::HistoryFlushOp", new HistoryFlushOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::HistoryMarkOp", new HistoryMarkOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::IfThenElseOp", new IfThenElseOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::IndividualSizeFrequencyStatsOp", new IndividualSizeFrequencyStatsOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::InvalidateFitnessOp", new InvalidateFitnessOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::MigrationBuffer", new MigrationBuffer::Alloc);
	lFactory.insertAllocator("Beagle::EC::MigrationGridOp", new MigrationGridOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::MigrationMapOp", new MigrationMapOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::MigrationRingOp", new MigrationRingOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::MilestoneWriteOp", new MilestoneWriteOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::MuCommaLambdaOp", new MuCommaLambdaOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::MuPlusLambdaOp", new MuPlusLambdaOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::OneCommaLambdaAdaptedOp", new OneCommaLambdaAdaptedOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::OversizeOp", new OversizeOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::PackageBase", new Beagle::EC::PackageBase::Alloc);
	lFactory.insertAllocator("Beagle::EC::RandomShuffleDemeOp", new RandomShuffleDemeOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::RegisterReadOp", new RegisterReadOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::SelectBestOp", new SelectBestOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::SelectFirstOp", new SelectFirstOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::SelectParsimonyTournOp", new SelectParsimonyTournOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::SelectRandomOp", new SelectRandomOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::SelectRouletteOp", new SelectRouletteOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::SelectTournamentOp", new SelectTournamentOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::SelectWorstOp", new SelectWorstOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::SelectWorstTournOp", new SelectWorstTournOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::StatsCalcFitnessSimpleOp", new StatsCalcFitnessSimpleOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::SteadyStateOp", new SteadyStateOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::TermMaxEvalsOp", new TermMaxEvalsOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::TermMaxFitnessOp", new TermMaxFitnessOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::TermMaxGenOp", new TermMaxGenOp::Alloc);
	lFactory.insertAllocator("Beagle::EC::TermMinFitnessOp", new TermMinFitnessOp::Alloc);

	// Set aliases
	lFactory.aliasAllocator("Beagle::EC::AdaptBreedingProbaOp", "AdaptBreedingProbaOp");
	lFactory.aliasAllocator("Beagle::EC::AlgoGenerational", "AlgoGenerational");
	lFactory.aliasAllocator("Beagle::EC::AlgoSequential", "AlgoSequential");
	lFactory.aliasAllocator("Beagle::EC::AlgoSteadyState", "AlgoSteadyState");
	lFactory.aliasAllocator("Beagle::EC::DecimateOp", "DecimateOp");
	lFactory.aliasAllocator("Beagle::EC::FitnessSimple", "FitnessSimple");
	lFactory.aliasAllocator("Beagle::EC::FitnessSimpleMin", "FitnessSimpleMin");
	lFactory.aliasAllocator("Beagle::EC::GenerationalOp", "GenerationalOp");
	lFactory.aliasAllocator("Beagle::EC::HierarchicalFairCompetitionOp", "HierarchicalFairCompetitionOp");
	lFactory.aliasAllocator("Beagle::EC::HistoryFlushOp", "HistoryFlushOp");
	lFactory.aliasAllocator("Beagle::EC::HistoryMarkOp", "HistoryMarkOp");
	lFactory.aliasAllocator("Beagle::EC::IfThenElseOp", "IfThenElseOp");
	lFactory.aliasAllocator("Beagle::EC::IndividualSizeFrequencyStatsOp", "IndividualSizeFrequencyStatsOp");
	lFactory.aliasAllocator("Beagle::EC::InvalidateFitnessOp", "InvalidateFitnessOp");
	lFactory.aliasAllocator("Beagle::EC::MigrationBuffer", "MigrationBuffer");
	lFactory.aliasAllocator("Beagle::EC::MigrationGridOp", "MigrationGridOp");
	lFactory.aliasAllocator("Beagle::EC::MigrationMapOp", "MigrationMapOp");
	lFactory.aliasAllocator("Beagle::EC::MigrationRingOp", "MigrationRingOp");
	lFactory.aliasAllocator("Beagle::EC::MilestoneWriteOp", "MilestoneWriteOp");
	lFactory.aliasAllocator("Beagle::EC::MuCommaLambdaOp", "MuCommaLambdaOp");
	lFactory.aliasAllocator("Beagle::EC::MuPlusLambdaOp", "MuPlusLambdaOp");
	lFactory.aliasAllocator("Beagle::EC::OneCommaLambdaAdaptedOp", "OneCommaLambdaAdaptedOp");
	lFactory.aliasAllocator("Beagle::EC::OversizeOp", "OversizeOp");
	lFactory.aliasAllocator("Beagle::EC::PackageBase", "PackageBase");
	lFactory.aliasAllocator("Beagle::EC::RandomShuffleDemeOp", "RandomShuffleDemeOp");
	lFactory.aliasAllocator("Beagle::EC::RegisterReadOp", "RegisterReadOp");
	lFactory.aliasAllocator("Beagle::EC::SelectBestOp", "SelectBestOp");
	lFactory.aliasAllocator("Beagle::EC::SelectFirstOp", "SelectFirstOp");
	lFactory.aliasAllocator("Beagle::EC::SelectParsimonyTournOp", "SelectParsimonyTournOp");
	lFactory.aliasAllocator("Beagle::EC::SelectRandomOp", "SelectRandomOp");
	lFactory.aliasAllocator("Beagle::EC::SelectRouletteOp", "SelectRouletteOp");
	lFactory.aliasAllocator("Beagle::EC::SelectTournamentOp", "SelectTournamentOp");
	lFactory.aliasAllocator("Beagle::EC::SelectWorstOp", "SelectWorstOp");
	lFactory.aliasAllocator("Beagle::EC::SelectWorstTournOp", "SelectWorstTournOp");
	lFactory.aliasAllocator("Beagle::EC::StatsCalcFitnessSimpleOp", "StatsCalcFitnessSimpleOp");
	lFactory.aliasAllocator("Beagle::EC::SteadyStateOp", "SteadyStateOp");
	lFactory.aliasAllocator("Beagle::EC::TermMaxEvalsOp", "TermMaxEvalsOp");
	lFactory.aliasAllocator("Beagle::EC::TermMaxFitnessOp", "TermMaxFitnessOp");
	lFactory.aliasAllocator("Beagle::EC::TermMaxGenOp", "TermMaxGenOp");
	lFactory.aliasAllocator("Beagle::EC::TermMinFitnessOp", "TermMinFitnessOp");


	// Set some basic concept-type associations in factory
	lFactory.setConcept("Fitness", "FitnessSimple");
	lFactory.setConcept("MigrationBuffer", "MigrationBuffer");
	lFactory.setConcept("StatsCalculateOp", "StatsCalcFitnessSimpleOp");
	lFactory.setConcept("SelectionOp", "SelectTournamentOp");
	lFactory.setConcept("MigrationOp", "MigrationRingOp");
	lFactory.setConcept("TerminationOp", "TermMaxGenOp");
	lFactory.setConcept("Algorithm", "AlgoSequential");

	Beagle_StackTraceEndM("void PackageBase::configureSystem(System&)");
}


/*!
 *  \brief List packages which current package depends.
 *  \return Bag with the packages instanciation on which current package depends.
 *
 *  PackageBase doesn't depend on any other packages, it is the basic package of all the
    others.
 */
Package::Bag Beagle::EC::PackageBase::listDependencies(void)
{
	Beagle_StackTraceBeginM();
	return Beagle::Package::Bag();
	Beagle_StackTraceEndM("Package::Bag PackageBase::listDependencies(void)");
}
