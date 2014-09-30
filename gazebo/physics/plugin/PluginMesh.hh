/*
 * Copyright (C) 2014 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef _GAZEBO_PluginMESH_HH_
#define _GAZEBO_PluginMESH_HH_

#include "gazebo/physics/plugin/PluginTypes.hh"
#include "gazebo/physics/MeshShape.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace physics
  {
    /// \brief Triangle mesh helper class.
    class GAZEBO_VISIBLE PluginMesh
    {
      /// \brief Constructor.
      public: explicit PluginMesh();

      /// \brief Destructor.
      public: virtual ~PluginMesh();

      /// \brief Create a mesh collision shape using a submesh.
      /// \param[in] _subMesh Pointer to the submesh.
      /// \param[in] _collision Pointer to the collsion object.
      /// \param[in] _scale Scaling factor.
      public: void Init(const common::SubMesh *_subMesh,
                PluginCollisionPtr _collision, const math::Vector3 &_scale);

      /// \brief Create a mesh collision shape using a mesh.
      /// \param[in] _mesh Pointer to the mesh.
      /// \param[in] _collision Pointer to the collsion object.
      /// \param[in] _scale Scaling factor.
      public: void Init(const common::Mesh *_mesh,
                PluginCollisionPtr _collision, const math::Vector3 &_scale);

      /// \brief Update the collision mesh.
      public: virtual void Update();

      /// \brief Transform matrix index.
      private: int transformIndex;

      /// \brief Array of vertex values.
      private: float *vertices;

      /// \brief Array of index values.
      private: int *indices;
    };
  }
}
#endif
