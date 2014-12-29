///
/// MeshData.h
/// Vorb Engine
///
/// Created by Cristian Zaloj on 18 Dec 2014
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// 
///

#pragma once

#ifndef MeshData_h__
#define MeshData_h__

namespace vorb {
    namespace core {
		namespace graphics {
            enum class VertexAttributeUsage {

            };

            struct VertexElement {
            public:
                VertexAttributeUsage usage : 4;
                ui32 usageIndex : 4;
                ui32 componentSize;
                ui32 componentCount;
                size_t offset;
            };



            typedef Array<VertexElement> VertexDeclaration;

            template<typename V, typename I>
            struct MeshData {
            public:
                V* vertices;
                size_t vertexCount;
                T* indices;
                size_t indexCount;
            };


            struct MeshDataRaw {
            public:
                template<typename V, typename I>
                MeshData<V, T> as() const {
                    MeshData<V, T> m;
                    m.vertices = vertices;
                    m.vertexCount = vertexCount;
                    m.indices = indices;
                    m.indexCount = indexCount;
                    return m;
                }

                void* vertices;
                size_t vertexCount;
                void* indices;
                size_t indexCount;
            };
		}
    }
}
namespace vg = vorb::core::graphics;

#endif // MeshData_h__