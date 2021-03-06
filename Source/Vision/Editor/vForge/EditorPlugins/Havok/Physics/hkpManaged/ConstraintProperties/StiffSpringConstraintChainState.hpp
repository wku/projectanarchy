/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#pragma once

#include <Vision/Runtime/EnginePlugins/Havok/HavokPhysicsEnginePlugin/vHavokPhysicsModule.hpp>
#include <Vision/Editor/vForge/EditorPlugins/Havok/Physics/hkpManaged/ConstraintProperties/ConstraintChainStateBase.hpp>

using namespace System;
using namespace System::Runtime::Serialization;
using namespace System::ComponentModel;

using namespace ManagedFramework;

using namespace CSharpFramework::UndoRedo;
using namespace CSharpFramework;

namespace HavokManaged
{
  /// \brief Managed property class for stiff spring constraint chains.
  /// 
  /// The StiffSpringConstraintChainState class exposes the properties for 
  /// stiff spring constraint chains and provides functions for 
  /// setting/retrieving them on the native description.
  [Serializable]
  public ref class StiffSpringConstraintChainState : public ConstraintChainStateBase
  {
  public:
    /// Constructor. Sets the default values.
    StiffSpringConstraintChainState();

    [PropertyOrder(50)]
    [Description("How far the pivot points are offset from each link end (in fractions of the link length)")]
    property float LinkPivotOffset
    {
      float get() { return m_fLinkPivotOffset; }
      void set(float fLinkPivotOffset) 
      {
        if (fLinkPivotOffset < 0.f)
          m_fLinkPivotOffset = 0.f;
        else if (fLinkPivotOffset > 0.5f)
          m_fLinkPivotOffset = 0.5f;
        else
          m_fLinkPivotOffset = fLinkPivotOffset;
      }
    }

    // Deserialisation method
    virtual void GetObjectData(SerializationInfo ^si, StreamingContext sc) override;

  protected:
    // Serialisation constructor
    StiffSpringConstraintChainState(SerializationInfo ^si, StreamingContext sc);

    /// Creates a new native description instance (initialized to defaults)
    virtual vHavokConstraintChainDesc *CreateNativeDesc() override;

    /// Fills this managed description with the content of the passed native description
    virtual void NativeToManaged(const vHavokConstraintChainDesc &nativeDesc) override;

    /// Fills the passed native description with the content of this managed description.
    virtual void ManagedToNative(vHavokConstraintChainDesc &nativeDesc) override;


  protected:
    float m_fLinkPivotOffset; ///< How far the pivot points are offset from each link end (in fractions of the link length)

    static const float s_fLinkPivotOffsetDefault = 0.25f;
  };
}

/*
 * Havok SDK - Base file, BUILD(#20131019)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2013
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available from salesteam@havok.com.
 * 
 */
