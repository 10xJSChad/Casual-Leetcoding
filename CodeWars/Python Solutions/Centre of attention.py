class Central_Pixels_Finder(Image):
    def central_pixels(self, color, profile=True):
        px_data, w, h = self.pixels, self.width, self.height
        make_offsets = lambda i : list(filter(lambda j : i != j and j not in visited_pixels, 
                                  (i-1 if i > 0 and i % w != 0 and px_data[i-1] == color else i,
                                   i+1 if i < w*h-1 and (i+1) % w != 0 and px_data[i+1] == color else i,
                                   i+w if i+w < w*h and px_data[i+w] == color else i,
                                   i-w if i-w > -1 and px_data[i-w] == color else i)))
        
        visited_pixels = {
            i for i, px in enumerate(px_data)
            if px == color and ((i < w or (i+1 > w*h - w and i < w*h) 
                                or (i % w == 0 or (i+1) % w == 0))
              or (i > 0 and i % w != 0 and px_data[i-1] != color) or 
              (i < w*h-1 and (i+1) % w != 0 and px_data[i+1] != color) or 
              ((i+w < w*h and px_data[i+w] != color)) or i-w > -1 and (px_data[i-w] != color))
        }
        
        
        def find_answer(px_list):     
            nonlocal visited_pixels
            deeper_pixels = {offset for offsets in 
                            [make_offsets(px) for px in px_list] 
                            for offset in offsets}
                
            if deeper_pixels == set(): 
                return list(px_list)
        
            visited_pixels = visited_pixels.union(deeper_pixels)
            return find_answer(deeper_pixels)    
        return find_answer(visited_pixels)
