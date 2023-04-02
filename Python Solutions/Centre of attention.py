from collections import defaultdict
class Central_Pixels_Finder(Image):
    
    def central_pixels(self, color, profile=True):
        px_data, w, h = self.pixels, self.width, self.height
        make_offsets = lambda x, y: ((x-1, y), 
                                     (x+1, y), 
                                     (x, y-1), 
                                     (x, y+1))
        
        coords_in_range = lambda x, y : x > -1 and x < w and y > -1 and y < h
        color_by_coords = lambda x, y : px_data[to_index(x, y)] 
        to_index = lambda x, y : x + (y * (w))
        to_coords = lambda i : (i % w, i // w)
        
        ans = []; ans_append = ans.append
        depth_map = defaultdict(int)
        
        def set_depth_if_in_contact(x, y, depth):
            offsets = make_offsets(x, y)
            test = [offset for offset in offsets
                   if offset not in depth_map and
                   coords_in_range(*offset) and
                   px_data[to_index(*offset)] == color]
            
            for offset in offsets:
                if not coords_in_range(*offset): continue
                if (offset not in depth_map and 
                px_data[to_index(*offset)] == color):
                    depth_map[offset] = depth
                    ans_append(to_index(*offset))
            
        ans_set = {
            i for i, px in enumerate(px_data)
            if px == color and ((i < w or (i+1 > w*h - w and i < w*h) 
                                or (i % w == 0 or (i+1) % w == 0))
              or (i > 0 and i % w != 0 and px_data[i-1] != color) or 
              (i < w*h-1 and (i+1) % w != 0 and px_data[i+1] != color) or 
              ((i+w < w*h and px_data[i+w] != color)) or i-w > -1 and (px_data[i-w] != color))
        }
            
        for i, px in enumerate(px_data):
            x, y = to_coords(i)
            if px != color: set_depth_if_in_contact(x, y, 1)
            elif (x == 0 or x == w-1) or (y == 0 or y ==h-1): 
                if (x, y) not in depth_map: 
                    depth_map[(x, y)] = 1
                    ans_append(to_index(x, y))  
                    
        def get_ans(min, max):
            for i in range(min, max):
                x, y = to_coords(ans[i])
                if (x, y) not in depth_map: 
                    depth_map[(x, y)] = 1
                    ans_append(to_index(x, y))  
                set_depth_if_in_contact(x, y, depth_map[i])
            
                if i == len(ans)-1: return ans[min:]
                elif i == max-1: return get_ans(max, len(ans))
            
            return []
        
        return get_ans(0, len(ans))
    
