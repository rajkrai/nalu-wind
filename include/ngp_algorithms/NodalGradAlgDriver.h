/*------------------------------------------------------------------------*/
/*  Copyright 2019 National Renewable Energy Laboratory.                  */
/*  This software is released under the license detailed                  */
/*  in the file, LICENSE, which is located in the top-level Nalu          */
/*  directory structure                                                   */
/*------------------------------------------------------------------------*/

#ifndef NODALGRADALGDRIVER_H
#define NODALGRADALGDRIVER_H

#include "ngp_algorithms/NgpAlgDriver.h"
#include "FieldTypeDef.h"

namespace sierra {
namespace nalu {

template<typename GradPhiType>
class NodalGradAlgDriver : public NgpAlgDriver
{
  static_assert(
    std::is_same<GradPhiType, VectorFieldType>::value ||
    std::is_same<GradPhiType, GenericFieldType>::value,
    "Invalid field type provided to NodalGradAlgDriver");

public:
  NodalGradAlgDriver(Realm&, const std::string&);

  virtual ~NodalGradAlgDriver() = default;

  //! Reset fields before calling algorithms
  virtual void pre_work() override;

  //! Synchronize fields after algorithms have done their work
  virtual void post_work() override;

private:
  //! Field that is synchronized pre/post updates
  const std::string gradPhiName_;
};

using ScalarNodalGradAlgDriver = NodalGradAlgDriver<VectorFieldType>;
using VectorNodalGradAlgDriver = NodalGradAlgDriver<GenericFieldType>;

}  // nalu
}  // sierra


#endif /* NODALGRADALGDRIVER_H */