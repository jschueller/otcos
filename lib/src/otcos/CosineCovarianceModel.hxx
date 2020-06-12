//                                               -*- C++ -*-
/**
 *
 *  Copyright 2005-2020 Airbus-EDF-IMACS-ONERA-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_COSINE_HXX
#define OPENTURNS_COSINE_HXX

#include "otcos/otcosprivate.hxx"
#include "openturns/StationaryCovarianceModel.hxx"

namespace OTCOS {

/**
 * @class CosineCovarianceModel
 */

class OTCOS_API CosineCovarianceModel
  : public OT::StationaryCovarianceModel
{

  CLASSNAME

public:

  /** Constructor based on input dimension */
  CosineCovarianceModel();

  /** Parameters constructor */
  CosineCovarianceModel(const OT::Point & scale, const OT::Point & amplitude, const OT::Scalar alpha = 1.0);

  /** Virtual copy constructor */
  CosineCovarianceModel * clone() const;

  /** Computation of the covariance function */
  using OT::StationaryCovarianceModel::computeStandardRepresentative;
  OT::Scalar computeStandardRepresentative(const OT::Point & tau) const;
#ifndef SWIG
  OT::Scalar computeStandardRepresentative(const OT::Collection<OT::Scalar>::const_iterator & s_begin,
                                       const OT::Collection<OT::Scalar>::const_iterator & t_begin) const;
#endif

  /** String converter */
  OT::String __repr__() const;

  /** String converter */
  OT::String __str__(const OT::String & offset = "") const;

  /** Method save() stores the object through the StorageManager */
  void save(OT::Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(OT::Advocate & adv);

private:

  OT::Scalar alpha_;

} ; /* class CosineCovarianceModel */

}

#endif
